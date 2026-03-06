//
// Created by x3r1x on 24.02.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int TOP_STRINGS_ARRAY_SIZE = 3;
constexpr int REGISTER_DIFFERENCE = 32;

char* reallocString();
int lowerSymbol(int symbol);
char* mallocConvertToLower(const char* inString);
void placeStringInTopArray(char* topArray[TOP_STRINGS_ARRAY_SIZE], char* str, bool* isError);
void printArray(char* array[TOP_STRINGS_ARRAY_SIZE]);

int main(void)
{
	int N;
	bool isError = false;
	char* topStrings[TOP_STRINGS_ARRAY_SIZE] = { nullptr, nullptr, nullptr };

	if (scanf("%d", &N) != 1)
	{
		printf("Error: Wrong input!\n");
		return 1;
	}

	getchar();

	for (int i = 0; i < N; ++i)
	{
		char* str = reallocString();

		if (str == nullptr)
		{
			printf("Error: Not enough memory\n");
			return 1;
		}

		placeStringInTopArray(topStrings, str, &isError);

		if (isError)
		{
			free(str);
			printf("Error: not enough memory!\n");
			return 1;
		}
	}

	printArray(topStrings);

	return 0;
}

char* reallocString()
{
	char* str = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		char* newStrPtr = realloc(str, len + 1);

		if (newStrPtr == nullptr)
		{
			goto error;
		}

		str = newStrPtr;
		str[len++] = (char)ch;
	}

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

int lowerSymbol(const int symbol)
{
	if ('A' <= symbol && symbol <= 'Z')
	{
		return symbol + REGISTER_DIFFERENCE;
	}

	return symbol;
}

char* mallocConvertToLower(const char* inString)
{
	const size_t inStringLen = strlen(inString);
	char* outString = malloc(inStringLen + 1);

	if (outString == nullptr)
	{
		return nullptr;
	}

	for (int i = 0; i < inStringLen; ++i)
	{
		outString[i] = lowerSymbol(inString[i]);
	}

	outString[inStringLen] = '\0';
	return outString;
}

void placeStringInTopArray(char* topArray[TOP_STRINGS_ARRAY_SIZE], char* str, bool* isError)
{
	int index = 0;
	char* loweredStr = mallocConvertToLower(str);
	char* lowerArrayString = nullptr;

	if (loweredStr == nullptr)
	{
		*isError = true;
		return;
	}

	// free str
	while (index < TOP_STRINGS_ARRAY_SIZE && topArray[index] != nullptr)
	{
		lowerArrayString = mallocConvertToLower(topArray[index]);

		if (lowerArrayString == nullptr)
		{
			free(loweredStr);
			*isError = true;
			return;
		}

		if (strcmp(loweredStr, lowerArrayString) < 0)
		{
			lowerArrayString = mallocConvertToLower(topArray[++index]);
		}
		else
		{
			break;
		}
	}

	if (index != TOP_STRINGS_ARRAY_SIZE)
	{
		for (int i = TOP_STRINGS_ARRAY_SIZE - 1; i > index; --i)
		{
			topArray[i] = topArray[i - 1];
		}

		topArray[index] = str;
	}

	free(loweredStr);
	free(lowerArrayString);
}

void printArray(char* array[TOP_STRINGS_ARRAY_SIZE])
{
	for (int i = 0; i < TOP_STRINGS_ARRAY_SIZE; ++i)
	{
		if (array[i] != nullptr)
		{
			printf("%s\n", array[i]);
		}
	}
}