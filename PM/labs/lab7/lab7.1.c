//
// Created by x3r1x on 18.04.2026.
//

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

constexpr int MAX_UINT8T_VALUE = 255;
constexpr int LEFT_BRACKET = '[';
constexpr int RIGHT_BRACKET = ']';

typedef enum
{
	COMPRESS,
	DECOMPRESS,
	ERROR
} ProgramType;

typedef struct
{
	uint8_t quantity;
	int symbolCode;
} SymbolQuantity;

bool IsWritingQuantitySuccessful(FILE** outFile, const SymbolQuantity symbolQuantity)
{
	if (fprintf(*outFile, "%c%d%c%c%c%c", LEFT_BRACKET, symbolQuantity.quantity, RIGHT_BRACKET, LEFT_BRACKET, symbolQuantity.symbolCode, RIGHT_BRACKET) == EOF)
	{
		return false;
	}

	return true;
}

bool IsIncrementingQuantitySuccessful(FILE** outFile, SymbolQuantity* symbolQuantity)
{
	if (symbolQuantity->quantity == MAX_UINT8T_VALUE)
	{
		if (!IsWritingQuantitySuccessful(outFile, *symbolQuantity))
		{
			return false;
		}

		symbolQuantity->quantity = 0;
	}
	else
	{
		symbolQuantity->quantity++;
	}

	return true;
}

bool IsChangingSymbolSuccessful(FILE** outFile, SymbolQuantity* symbolQuantity, const int newSymbol)
{
	if (symbolQuantity->symbolCode != 0 && !IsWritingQuantitySuccessful(outFile, *symbolQuantity))
	{
		return false;
	}

	symbolQuantity->quantity = 1;
	symbolQuantity->symbolCode = newSymbol;

	return true;
}

bool IsCompressSuccessful(FILE** inFile, FILE** outFile)
{
	int ch;
	SymbolQuantity currentQuantity = { 0 };

	while ((ch = fgetc(*inFile)) != EOF)
	{
		if (ch == currentQuantity.symbolCode && !IsIncrementingQuantitySuccessful(outFile, &currentQuantity))
		{
			return false;
		}

		if (ch != currentQuantity.symbolCode && !IsChangingSymbolSuccessful(outFile, &currentQuantity, ch))
		{
			return false;
		}
	}

	if (!IsWritingQuantitySuccessful(outFile, currentQuantity))
	{

		return false;
	}

	return true;
}

bool IsReadingQuantitySuccessful(FILE** inFile, SymbolQuantity* symbolQuantity, bool* isReadingQuantity, const int ch)
{
	if ((ch != LEFT_BRACKET && ch != RIGHT_BRACKET) || isReadingQuantity == nullptr || !*isReadingQuantity)
	{
		return false;
	}

	if (ch == LEFT_BRACKET && fscanf(*inFile, "%hhu", &symbolQuantity->quantity) != 1)
	{
		return false;
	}

	if (ch == RIGHT_BRACKET)
	{
		*isReadingQuantity = false;
	}

	return true;
}

bool IsReadingSymbolSuccessful(FILE** inFile, SymbolQuantity* symbolQuantity, bool* isReadingQuantity, int ch)
{
	if ((ch != LEFT_BRACKET && ch != RIGHT_BRACKET) || isReadingQuantity == nullptr || *isReadingQuantity)
	{
		return false;
	}

	if (ch == LEFT_BRACKET)
	{
		char symbol;

		if (fscanf(*inFile, "%c", &symbol) != 1)
		{
			return false;
		}

		symbolQuantity->symbolCode = (int)symbol;
	}

	if (ch == RIGHT_BRACKET)
	{
		*isReadingQuantity = true;
	}

	return true;
}

bool IsWritingUnpackedQuantitySuccessful(FILE** outFile, const SymbolQuantity quantity)
{
	for (int i = 0; i < quantity.quantity; i++)
	{
		if (fprintf(*outFile, "%c", quantity.symbolCode) == EOF)
		{
			return false;
		}
	}

	return true;
}

bool IsDecompressSuccessful(FILE** inFile, FILE** outFile)
{
	int ch;
	bool isReadingQuantity = true;
	SymbolQuantity currentQuantity = { 0 };

	while ((ch = fgetc(*inFile)) != EOF)
	{
		if (isReadingQuantity)
		{
			if (!IsReadingQuantitySuccessful(inFile, &currentQuantity, &isReadingQuantity, ch))
			{
				fprintf(stderr, "Error reading quantity!\n");
				return false;
			}
		}
		else
		{
			if (!IsReadingSymbolSuccessful(inFile, &currentQuantity, &isReadingQuantity, ch))
			{
				fprintf(stderr, "Error reading symbol!\n");
				return false;
			}

			if (isReadingQuantity == true)
			{
				if (!IsWritingUnpackedQuantitySuccessful(outFile, currentQuantity))
				{
					fprintf(stderr, "Error writing symbols!\n");
					return false;
				}

				currentQuantity.quantity = 0;
				currentQuantity.symbolCode = 0;
			}
		}
	}

	return true;
}

ProgramType InitAndGetType(const int argc, char* argv[], FILE** inFile, FILE** outFile)
{
	if (argc != 4)
	{
		fprintf(stderr, "Wrong format!\n");
		return ERROR;
	}

	ProgramType mode;

	if (strcmp("-compress", argv[1]) == 0)
	{
		mode = COMPRESS;
	}
	else if (strcmp("-decompress", argv[1]) == 0)
	{
		mode = DECOMPRESS;
	}
	else
	{
		mode = ERROR;
	}

	*inFile = fopen(argv[2], "r");

	if (*inFile == NULL)
	{
		fprintf(stderr, "Error opening file, %s!\n", argv[2]);
		return ERROR;
	}

	*outFile = fopen(argv[3], "w");

	if (*outFile == NULL)
	{
		fprintf(stderr, "Error opening file, %s!\n", argv[3]);
		return ERROR;
	}

	return mode;
}

bool IsClosingFilesSuccessful(FILE** inFile, FILE** outFile)
{
	if (fclose(*inFile) == EOF || fclose(*outFile) == EOF)
	{
		return false;
	}

	return true;
}

int main(const int argc, char* argv[])
{
	FILE* inFile;
	FILE* outFile;

	const ProgramType mode = InitAndGetType(argc, argv, &inFile, &outFile);

	if (mode == COMPRESS && !IsCompressSuccessful(&inFile, &outFile))
	{
		fprintf(stderr, "Failed to compress!\n");
	}
	if (mode == DECOMPRESS && !IsDecompressSuccessful(&inFile, &outFile))
	{
		fprintf(stderr, "failed to decompress!\n");
	}

	if (mode == ERROR)
	{
		fprintf(stderr, "Failed to handle!\n");
	}

	if (!IsClosingFilesSuccessful(&inFile, &outFile))
	{
		fprintf(stderr, "Failed to close files!\n");
	}
}