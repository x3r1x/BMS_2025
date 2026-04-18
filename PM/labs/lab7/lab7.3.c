//
// Created by x3r1x on 17.04.2026.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int COMMA = ',';

typedef struct
{
	char* name;
	long quantity;
	double price;
} Good;

char* ReadString(FILE* inFile, bool* isEOF)
{
	char* str = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = fgetc(inFile)) != '\n' && ch != EOF)
	{
		char* newStrPtr = realloc(str, len + 1);

		if (newStrPtr == nullptr)
		{
			goto error;
		}

		str = newStrPtr;
		str[len++] = (char)ch;
	}

	*isEOF = ch == EOF;

	char* newStrPtr = realloc(str, len + 1);

	if (newStrPtr == nullptr)
	{
		goto error;
	}

	str = newStrPtr;
	str[len] = '\0';
	return str;

error:
	free(str);
	return nullptr;
}

char* GetSubstringBeforeSymbol(const char* string, const char symbol)
{
	char* symbolPtr = strchr(string, symbol);

	if (symbolPtr == nullptr)
	{
		return nullptr;
	}

	const size_t substringLen = symbolPtr - string;
	char* substring = malloc(substringLen + 1);

	if (substring == nullptr)
	{
		return nullptr;
	}

	memcpy(substring, string, substringLen);
	substring[substringLen] = '\0';

	return substring;
}

Good ParseStringAndGetGood(char* currentBuffer, bool* isError)
{
	Good good = { 0 };
	char* currentStartMark = currentBuffer;
	char* goodName = GetSubstringBeforeSymbol(currentStartMark, COMMA);

	if (goodName == nullptr)
	{
		*isError = true;
		return good;
	}

	good.name = goodName;
	currentStartMark += strlen(good.name) + 1;
	char* goodQuantity = GetSubstringBeforeSymbol(currentStartMark, COMMA);

	if (goodQuantity == nullptr)
	{
		free(good.name);
		*isError = true;
		return good;
	}

	currentStartMark += strlen(goodQuantity) + 1;
	good.quantity = strtol(goodQuantity, nullptr, 0);

	if (good.quantity < 0)
	{
		free(good.name);
		*isError = true;
		return good;
	}

	free(goodQuantity);

	if (currentStartMark == nullptr)
	{
		free(good.name);
		*isError = true;
		return good;
	}

	good.price = strtod(currentStartMark, nullptr);

	if (good.price < 0)
	{
		free(good.name);
		*isError = true;
		return good;
	}

	return good;
}

bool IsFillGoodArraySuccessful(Good** goodArray, int* goodArraySize, FILE* inFile)
{
	char* currentBuffer;
	bool isEOF = false;
	bool isError = false;

	while (!isEOF && (currentBuffer = ReadString(inFile, &isEOF)) != nullptr)
	{
		const Good good = ParseStringAndGetGood(currentBuffer, &isError);

		if (isError)
		{
			free(currentBuffer);
			return false;
		}

		Good* newGoodArrayPtr = realloc(*goodArray, sizeof(Good) * (*goodArraySize + 1));

		if (newGoodArrayPtr == nullptr)
		{
			free(currentBuffer);
			return false;
		}

		newGoodArrayPtr[(*goodArraySize)++] = good;
		*goodArray = newGoodArrayPtr;
		free(currentBuffer);
	}

	return true;
}

char* GetLoweredString(const char* inString)
{
	char* loweredString = malloc(strlen(inString) + 1);

	if (loweredString == nullptr)
	{
		return nullptr;
	}

	for (size_t i = 0; i < strlen(inString); i++)
	{
		loweredString[i] = (char)tolower(inString[i]);
	}

	loweredString[strlen(inString)] = '\0';

	return loweredString;
}

double GetTotalPriceAndPrintElements(Good* goodArray, int goodArraySize, char* substring, bool* isError)
{
	double totalPrice = 0;
	*isError = false;

	for (size_t i = 0; i < goodArraySize; i++)
	{
		char* loweredString = GetLoweredString(goodArray[i].name);

		if (loweredString == nullptr)
		{
			*isError = true;
			return totalPrice;
		}

		if (strstr(loweredString, substring) != nullptr)
		{
			totalPrice += goodArray[i].price * goodArray[i].quantity;
			printf("%s,%ld,%lf\n", goodArray[i].name, goodArray[i].quantity, goodArray[i].price);
		}

		free(loweredString);
	}

	return totalPrice;
}

void StartSubstringResearch(Good* goodArray, int goodArraySize)
{
	bool isEOF = false;
	bool isError = false;

	while (!isEOF)
	{
		char* currentSubstring = ReadString(stdin, &isEOF);

		double totalPrice = GetTotalPriceAndPrintElements(goodArray, goodArraySize, currentSubstring, &isError);

		if (isError)
		{
			free(currentSubstring);
			printf("Error: not enough memory!\n");
			return;
		}

		printf("Total price: %f\n", totalPrice);
		free(currentSubstring);
	}
}

void FreeNames(const Good* goodArray, const int goodArraySize)
{
	for (size_t i = 0; i < goodArraySize; i++)
	{
		free(goodArray[i].name);
	}
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		perror("Wrong amount of parameters!\n");
		return 1;
	}

	FILE* csvFile = fopen(argv[1], "r");

	if (csvFile == NULL)
	{
		perror("Error opening file!\n");
		return 1;
	}

	Good* goods = nullptr;
	int goodsCount = 0;

	if (!IsFillGoodArraySuccessful(&goods, &goodsCount, csvFile))
	{
		FreeNames(goods, goodsCount);
		free(goods);
		perror("Error filling goods into array!\n");
		return 1;
	}

	StartSubstringResearch(goods, goodsCount);

	if (ferror(csvFile))
	{
		perror("Error reading a string from a file!\n");
		return 1;
	}

	FreeNames(goods, goodsCount);
	free(goods);
	if (fclose(csvFile) == EOF)
	{
		perror("Error closing file!\n");
		return 1;
	}
}