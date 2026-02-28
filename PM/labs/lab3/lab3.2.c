//
// Created by x3r1x on 24.02.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int TOP_STRINGS_ARRAY_SIZE = 3;
constexpr int REGISTER_DIFFERENCE = 32;

char* readString();
char* toLower(const char* inString);
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
		char* str = readString();

		if (str == nullptr)
		{
			free(str);
			printf("Error: Not enough memory\n");
			return 1;
		}

		placeStringInTopArray(topStrings, str, &isError);

		if (isError)
	}

	printArray(topStrings);

	return 0;

	error:
		free()
}

char* readString()
{
	char* str = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		char* newStrPtr = realloc(str, len + 1);

		if (newStrPtr == nullptr)
		{
			free(str);
			return nullptr;
		}

		str = newStrPtr;
		str[len++] = (char)ch;
	}

	char* newStrPtr = realloc(str, len + 1);

	if (newStrPtr == nullptr)
	{
		free(str);
		return nullptr;
	}

	str = newStrPtr;

	str[len] = '\0';
	return str;
}

char* toLower(const char* inString)
{
	char* newStr = nullptr;
	size_t newStrLen = 0;
	size_t inStringLen = strlen(inString);

	for (int i = 0; i < inStringLen; ++i)
	{
		char* newStrPtr = realloc(newStr, newStrLen + 1);

		if (newStrPtr == nullptr)
		{
			free(newStr);
			return nullptr;
		}

		newStr = newStrPtr;
		int ch = inString[i];

		if ('A' <= inString[i] && inString[i] <= 'Z')
		{
			ch += REGISTER_DIFFERENCE;
		}

		newStr[newStrLen++] = (char)ch;
	}

	char* newStrPtr = realloc(newStr, newStrLen + 1);

	if (newStrPtr == nullptr)
	{
		free(newStr);
		return nullptr;
	}

	newStr = newStrPtr;
	newStr[newStrLen] = '\0';
	return newStr;
}

void placeStringInTopArray(char* topArray[TOP_STRINGS_ARRAY_SIZE], char* str, bool* isError)
{
	int index = 0;
	char* loweredStr = toLower(str);

	if (loweredStr == nullptr)
	{
		*isError = true;
		return;
	}

	// free str
	// rename
	while (index < TOP_STRINGS_ARRAY_SIZE && topArray[index] != nullptr && strcmp(toLower(str), toLower(topArray[index])) < 0)
	{
		char* loweredComparingStr = toLower(topArray[index]);

		if (loweredComparingStr == nullptr)
		{
			free(loweredStr);
			*isError = true;
			return;
		}

		if (strcmp(loweredStr, loweredComparingStr) < 0)
		{
			++index;
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