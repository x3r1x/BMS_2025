//
// Created by x3r1x on 18.04.2026.
//

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

constexpr int LEFT_BRACKET = '[';
constexpr int RIGHT_BRACKET = ']';
constexpr int COMMA = ',';
constexpr int SPACE = ' ';

typedef enum
{
	COMPRESS,
	DECOMPRESS,
	ERROR
} ProgramType;

typedef struct
{
	int8_t quantity;
	int symbolCodes[INT8_MAX + 1];
} SymbolQuantity;

bool IsWritingQuantitySuccessful(FILE** outFile, const SymbolQuantity symbolQuantity)
{
	if (symbolQuantity.quantity >= 0 && fprintf(*outFile, "%c%d%c%c%c%c", LEFT_BRACKET, symbolQuantity.quantity, RIGHT_BRACKET, LEFT_BRACKET, symbolQuantity.symbolCodes[0], RIGHT_BRACKET) == EOF)
	{
		return false;
	}

	if (symbolQuantity.quantity < 0)
	{
		if (fprintf(*outFile, "%c%d", LEFT_BRACKET, symbolQuantity.quantity) == EOF)
		{
			return false;
		}

		for (int i = 0; i < -symbolQuantity.quantity; i++)
		{
			if (fprintf(*outFile, "%c %c", COMMA, symbolQuantity.symbolCodes[i]) == EOF)
			{
				return false;
			}
		}

		if (fprintf(*outFile, "%c", RIGHT_BRACKET) == EOF)
		{
			return false;
		}
	}

	return true;
}

bool IsIncrementingQuantitySuccessful(FILE** outFile, SymbolQuantity* symbolQuantity)
{
	if (symbolQuantity->quantity == INT8_MAX)
	{
		if (!IsWritingQuantitySuccessful(outFile, *symbolQuantity))
		{
			return false;
		}

		symbolQuantity->quantity = 1;
	}
	else
	{
		symbolQuantity->quantity++;
	}

	return true;
}

bool IsChangingSymbolSuccessful(FILE** outFile, SymbolQuantity* symbolQuantity, const int newSymbol)
{
	if (symbolQuantity->symbolCodes[0] != 0 && !IsWritingQuantitySuccessful(outFile, *symbolQuantity))
	{
		return false;
	}

	symbolQuantity->quantity = 1;
	symbolQuantity->symbolCodes[0] = newSymbol;

	return true;
}

//FIXME: rename
bool IsCompressSuccessful(FILE** inFile, FILE** outFile)
{
	int ch;
	SymbolQuantity currentQuantity = {
		.quantity = -1,
		.symbolCodes = 0
	};

	if ((currentQuantity.symbolCodes[0] = fgetc(*inFile)) == EOF)
	{
		return false;
	}

	while ((ch = fgetc(*inFile)) != EOF)
	{
		if (currentQuantity.quantity >= 0)
		{
			if (currentQuantity.symbolCodes[0] == ch)
			{
				if (!IsIncrementingQuantitySuccessful(outFile, &currentQuantity))
				{
					return false;
				}
			}
			else
			{
				if (!IsWritingQuantitySuccessful(outFile, currentQuantity))
				{
					return false;
				}

				currentQuantity.quantity = -1;
				currentQuantity.symbolCodes[0] = ch;
			}
		}
		else
		{
			if (currentQuantity.symbolCodes[-currentQuantity.quantity - 1] == ch)
			{
				currentQuantity.quantity++;

				if (currentQuantity.quantity != 0 && !IsWritingQuantitySuccessful(outFile, currentQuantity))
				{
					return false;
				}

				currentQuantity.quantity = 0;
				currentQuantity.symbolCodes[0] = ch;
			}
			else
			{
				if (currentQuantity.quantity == INT8_MIN)
				{
					if (!IsWritingQuantitySuccessful(outFile, currentQuantity))
					{
						return false;
					}

					currentQuantity.quantity = -1;
					currentQuantity.symbolCodes[0] = ch;
				}
				else
				{
					currentQuantity.symbolCodes[-currentQuantity.quantity--] = ch;
				}
			}
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
	if (isReadingQuantity == nullptr || !*isReadingQuantity)
	{
		return false;
	}

	if (ch == LEFT_BRACKET && fscanf(*inFile, "%hhd", &symbolQuantity->quantity) != 1)
	{
		return false;
	}

	*isReadingQuantity = false;

	return true;
}

bool IsReadingSymbolsSuccessful(FILE** inFile, SymbolQuantity* symbolQuantity, bool* isReadingQuantity, const int ch)
{
	if (isReadingQuantity == nullptr || *isReadingQuantity)
	{
		return false;
	}

	if (fgetc(*inFile) == EOF)
	{
		printf("There %c!\n", ch);
		return false;
	}

	char symbol;

	if (fscanf(*inFile, "%c", &symbol) != 1)
	{
		return false;
	}

	symbolQuantity->symbolCodes[0] = (int)symbol;

	for (int i = 1; i < -symbolQuantity->quantity; i++)
	{
		if (fgetc(*inFile) != COMMA || fgetc(*inFile) != SPACE)
		{
			return false;
		}

		char symbol1;

		if (fscanf(*inFile, "%c", &symbol1) != 1)
		{
			return false;
		}

		symbolQuantity->symbolCodes[i] = (int)symbol1;
	}

	if (fgetc(*inFile) == RIGHT_BRACKET)
	{
		*isReadingQuantity = true;
	}
	else
	{
		return false;
	}

	return true;
}

bool IsWritingUnpackedQuantitySuccessful(FILE** outFile, const SymbolQuantity quantity)
{
	if (quantity.quantity >= 0)
	{
		for (int i = 0; i < quantity.quantity + 2; i++)
		{
			if (fprintf(*outFile, "%c", quantity.symbolCodes[0]) == EOF)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < -quantity.quantity; i++)
		{
			if (fprintf(*outFile, "%c", quantity.symbolCodes[i]) == EOF)
			{
				return false;
			}
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
			if (!IsReadingSymbolsSuccessful(inFile, &currentQuantity, &isReadingQuantity, ch))
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
				currentQuantity.symbolCodes[0] = 0;
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

		if (fclose(*inFile) == EOF)
		{
			fprintf(stderr, "Error closing file, %s!\n", argv[2]);
		}

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
		return 1;
	}
	if (mode == DECOMPRESS && !IsDecompressSuccessful(&inFile, &outFile))
	{
		fprintf(stderr, "failed to decompress!\n");
		return 1;
	}

	if (mode == ERROR)
	{
		fprintf(stderr, "Failed to handle!\n");
		return 1;
	}

	if (!IsClosingFilesSuccessful(&inFile, &outFile))
	{
		fprintf(stderr, "Failed to close files!\n");
		return 1;
	}
}