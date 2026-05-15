//
// Created by x3r1x on 22.04.2026.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int BYTE = 8;
constexpr int MASK = UINT8_MAX;
constexpr int FILE_START = 0;
constexpr int ZERO = 0;
constexpr int BI_BIT_COUNT_OFFSET = 28;
constexpr int NEEDED_BIT_COUNT = 24;
constexpr double LIGHTEN_AMOUNT = 1.25;
constexpr int BI_COMPRESSION_OFFSET = 30;
constexpr int NEEDED_BI_COMPRESSION = 0;
constexpr int BI_WIDTH_OFFSET = 18;
constexpr int BI_HEIGHT_OFFSET = 22;
constexpr int BI_PIXELS_START = 54;

typedef enum
{
	ROTATE_CW,
	FLIP_H,
	FLIP_V,
	INVERT,
	LIGHTEN,
	ERROR
} ProgramType;

typedef struct
{
	uint8_t B;
	uint8_t G;
	uint8_t R;
} Color;

typedef struct
{
	uint32_t height;
	uint32_t width;
	uint32_t rowSize;
} ImageSize;

void U16ToLE(const uint16_t x, uint8_t out[2])
{
	out[0] = (uint8_t)(x & MASK);
	out[1] = (uint8_t)(x >> BYTE & MASK);
}

bool IsBfTypeCorrect(FILE** inFile)
{
	uint16_t bfTypeRaw;
	uint8_t bfTypeTransformed[2];

	if (fread(&bfTypeRaw, sizeof(bfTypeRaw), 1, *inFile) == EOF)
	{
		return false;
	}

	U16ToLE(bfTypeRaw, bfTypeTransformed);

	return bfTypeTransformed[0] == 'B' && bfTypeTransformed[1] == 'M';
}

bool IsBiBitCountCorrect(FILE** inFile)
{
	uint16_t biBitCountRaw;
	uint8_t biBitCountTransformed[2];

	if (fseek(*inFile, BI_BIT_COUNT_OFFSET, SEEK_SET) != 0
		|| fread(&biBitCountRaw, sizeof(biBitCountRaw), 1, *inFile) == EOF)
	{
		return false;
	}

	U16ToLE(biBitCountRaw, biBitCountTransformed);

	return biBitCountTransformed[0] == NEEDED_BIT_COUNT && biBitCountTransformed[1] == 0x00;
}

bool IsBiCompressionCorrect(FILE** inFile)
{
	uint32_t biCompressionRaw;

	if (fseek(*inFile, BI_COMPRESSION_OFFSET, SEEK_SET) != 0
		|| fread(&biCompressionRaw, sizeof(biCompressionRaw), 1, *inFile) == EOF)
	{
		return false;
	}

	return biCompressionRaw == NEEDED_BI_COMPRESSION;
}

bool IsInFileCorrect(FILE** inFile)
{
	return IsBfTypeCorrect(inFile) && IsBiBitCountCorrect(inFile) && IsBiCompressionCorrect(inFile);
}

bool GetImageSize(FILE** inFile, ImageSize* size)
{
	uint32_t biHeightRow;
	uint32_t biWidthRow;

	if (fseek(*inFile, BI_HEIGHT_OFFSET, SEEK_SET) != 0
		|| fread(&biHeightRow, sizeof(biHeightRow), 1, *inFile) == EOF)
	{
		return false;
	}

	if (fseek(*inFile, BI_WIDTH_OFFSET, SEEK_SET) != 0
		|| fread(&biWidthRow, sizeof(biWidthRow), 1, *inFile) == EOF)
	{
		return false;
	}

	size->height = biHeightRow;
	size->width = biWidthRow;
	size->rowSize = (biWidthRow * 3 + 3) / 4 * 4;

	return true;
}

bool GoToPixelsStart(FILE** inFile)
{
	if (fseek(*inFile, BI_PIXELS_START, SEEK_SET) != 0)
	{
		return false;
	}

	return true;
}

ProgramType InitAndGetProgramType(const int argc, char* argv[], FILE** inFile, FILE** outFile)
{
	if (argc != 4)
	{
		fprintf(stderr, "Error: wrong format!\n");
		return ERROR;
	}

	ProgramType mode;

	if (strcmp(argv[3], "rotate_cw") == 0)
	{
		mode = ROTATE_CW;
	}
	else if (strcmp(argv[3], "flip_h") == 0)
	{
		mode = FLIP_H;
	}
	else if (strcmp(argv[3], "flip_v") == 0)
	{
		mode = FLIP_V;
	}
	else if (strcmp(argv[3], "invert") == 0)
	{
		mode = INVERT;
	}
	else if (strcmp(argv[3], "lighten") == 0)
	{
		mode = LIGHTEN;
	}
	else
	{
		return ERROR;
	}

	*inFile = fopen(argv[1], "rb");

	if (*inFile == NULL)
	{
		fprintf(stderr, "Error opening file %s!\n", argv[1]);
		return ERROR;
	}

	*outFile = fopen(argv[2], "wb");

	if (*outFile == NULL)
	{
		fprintf(stderr, "Error opening file %s!\n", argv[2]);

		if (fclose(*inFile) == EOF)
		{
			fprintf(stderr, "Error closing file %s!\n", argv[1]);
		}

		return ERROR;
	}

	return mode;
}

bool CloseFiles(FILE** inFile, FILE** outFile)
{
	if (fclose(*inFile) == EOF || fclose(*outFile) == EOF)
	{
		return false;
	}

	return true;
}

bool HandlePadding(const uint32_t paddingSize, FILE** inFile, FILE** outFile)
{
	if (paddingSize != 0)
	{
		if (fseek(*inFile, paddingSize, SEEK_CUR) != 0)
		{
			return false;
		}

		for (int i = 0; i < paddingSize; i++)
		{
			fwrite(&ZERO, sizeof(ZERO), 1, *outFile);
		}
	}

	return true;
}

bool ReadImageToMemory(FILE** inFile, Color* image, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;

	for (int i = 0; i < size.height; i++)
	{
		if (fread(image + i * size.width, sizeof(Color), size.width, *inFile) != size.width)
		{
			return false;
		}

		if (paddingSize > 0 && fseek(*inFile, paddingSize, SEEK_CUR) != 0)
		{
			return false;
		}
	}

	return true;
}

bool WriteRotatedCWFromMemory(FILE** outFile, Color* image, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;

	for (int j = 0; j < size.width; j++)
	{
		for (int i = 0; i < size.height; i++)
		{
			if (fwrite(image + i * size.width + j, sizeof(Color), 1, *outFile) != 1)
			{
				return false;
			}
		}

		if (paddingSize > 0 && fwrite(&ZERO, sizeof(ZERO), paddingSize, *outFile) != 0)
		{
			return false;
		}
	}

	return true;
}

bool RotateCW(FILE** inFile, FILE** outFile, const ImageSize size)
{
	Color* image = malloc(sizeof(Color) * size.width * size.height);

	if (image == nullptr)
	{
		return false;
	}

	if (!ReadImageToMemory(inFile, image, size) || !WriteRotatedCWFromMemory(outFile, image, size))
	{
		free(image);
		return false;
	}

	free(image);
	return true;
}

bool ReadRow(FILE** inFile, Color* row, const uint32_t rowSize)
{
	if (fread(row, sizeof(Color), rowSize, *inFile) != rowSize)
	{
		return false;
	}

	return true;
}

bool WriteInversedRow(FILE** outFile, Color* row, const uint32_t rowSize)
{
	for (int i = (int)rowSize - 1; i >= 0; i--)
	{
		if (fwrite(&row[i], sizeof(Color), 1, *outFile) != 1)
		{
			return false;
		}
	}

	return true;
}

bool FlipH(FILE** inFile, FILE** outFile, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;
	Color* row = malloc(sizeof(Color) * size.width);

	if (row == nullptr)
	{
		return false;
	}

	for (int i = 0; i < size.height; i++)
	{
		if (!ReadRow(inFile, row, size.width) || !WriteInversedRow(outFile, row, size.width) || !HandlePadding(paddingSize, inFile, outFile))
		{
			free(row);
			return false;
		}
	}

	free(row);
	return true;
}

bool WriteFlippedVFromMemory(FILE** outFile, Color* image, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;

	for (int i = (int)size.height - 1; i >= 0; i--)
	{
		if (fwrite(image + i * size.width, 1, size.rowSize, *outFile) != size.rowSize)
		{
			return false;
		}

		if (paddingSize > 0 && fwrite(&ZERO, sizeof(ZERO), paddingSize, *outFile) != 0)
		{
			return false;
		}
	}

	return true;
}

bool FlipV(FILE** inFile, FILE** outFile, const ImageSize size)
{
	Color* image = malloc(sizeof(Color) * size.width * size.height);

	if (image == nullptr)
	{
		return false;
	}

	if (!ReadImageToMemory(inFile, image, size) || !WriteFlippedVFromMemory(outFile, image, size))
	{
		free(image);
		return false;
	}

	free(image);
	return true;
}

bool Invert(FILE** inFile, FILE** outFile, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;

	for (int i = 0; i < size.height; i++)
	{
		for (int j = 0; j < size.height; j++)
		{
			Color pixel;

			if (fread(&pixel, sizeof(pixel), 1, *inFile) != 1)
			{
				return false;
			}

			pixel.B = UINT8_MAX - pixel.B;
			pixel.G = UINT8_MAX - pixel.G;
			pixel.R = UINT8_MAX - pixel.R;

			if (fwrite(&pixel, sizeof(pixel), 1, *outFile) != 1)
			{
				return false;
			}
		}

		if (!HandlePadding(paddingSize, inFile, outFile))
		{
			return false;
		}
	}

	return true;
}

void LightenComponent(uint8_t* component)
{
	if ((double)*component * LIGHTEN_AMOUNT > UINT8_MAX)
	{
		*component = UINT8_MAX;
	}
	else
	{
		*component = (double)*component * LIGHTEN_AMOUNT;
	}
}

bool Lighten(FILE** inFile, FILE** outFile, const ImageSize size)
{
	const uint32_t paddingSize = size.rowSize - size.width * 3;

	for (int i = 0; i < size.height; i++)
	{
		for (int j = 0; j < size.width; j++)
		{
			Color pixel;

			if (fread(&pixel, sizeof(pixel), 1, *inFile) != 1)
			{
				return false;
			}

			LightenComponent(&pixel.B);
			LightenComponent(&pixel.G);
			LightenComponent(&pixel.R);

			if (fwrite(&pixel, sizeof(pixel), 1, *outFile) != 1)
			{
				return false;
			}
		}

		if (!HandlePadding(paddingSize, inFile, outFile))
		{
			return false;
		}
	}

	return true;
}

bool CopyServiceInformation(FILE** inFile, FILE** outFile)
{
	if (fseek(*inFile, FILE_START, SEEK_SET) != 0)
	{
		return false;
	}

	uint8_t serviceInfo[BI_PIXELS_START];
	if (fread(serviceInfo, BI_PIXELS_START, 1, *inFile) != 1 || fwrite(serviceInfo, BI_PIXELS_START, 1, *outFile) != 1)
	{
		return false;
	}

	return true;
}

bool HandleOperation(ProgramType operation, FILE** inFile, FILE** outFile)
{
	ImageSize imageSize;

	if (!IsInFileCorrect(inFile) || !GetImageSize(inFile, &imageSize) || !CopyServiceInformation(inFile, outFile) || !GoToPixelsStart(inFile))
	{
		return false;
	}

	switch (operation)
	{
	case ROTATE_CW:
		return RotateCW(inFile, outFile, imageSize);
	case FLIP_H:
		return FlipH(inFile, outFile, imageSize);
	case FLIP_V:
		return FlipV(inFile, outFile, imageSize);
	case INVERT:
		return Invert(inFile, outFile, imageSize);
	case LIGHTEN:
		return Lighten(inFile, outFile, imageSize);
	case ERROR:
		return false;
	}

	return true;
}

int main(const int argc, char* argv[])
{
	FILE* inFile;
	FILE* outFile;

	const ProgramType mode = InitAndGetProgramType(argc, argv, &inFile, &outFile);

	if (mode == ERROR)
	{
		fprintf(stderr, "Wrong format!\n");
		return 1;
	}

	if (!HandleOperation(mode, &inFile, &outFile))
	{
		fprintf(stderr, "Error doing operation!\n");
		return 1;
	}

	if (!CloseFiles(&inFile, &outFile))
	{
		fprintf(stderr, "Error closing files!\n");
		return 1;
	}
}