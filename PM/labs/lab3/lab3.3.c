//
// Created by x3r1x on 27.02.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int REGISTER_DIFFERENCE = 32;
constexpr int NO_INDEX_FOUND = -1;
constexpr int ERROR = -2;

char* readWord(bool* isEnd, bool* isMemoryExceeded);
int lowerSymbol(int symbol);
char* mallocConvertToLower(const char* inString);
int getArrayIndexOfAWord(char** array, int len, const char* str, bool* isError);
int findPlacementIndex(char** array, int len, const char* str, bool* isError);
char** placeWordInArrayByIndex(char** array, int len, int index, char* str, bool* isError);
int* placeCountValueByIndex(int* array, int len, int index, bool* isError);
void printCounts(char** stringArray, const int* countsArray, int len);

int main(void)
{
	char** words = nullptr;
	int* counts = nullptr;
	int totalWordsCount = 0;
	bool isEnd = false;

	while (!isEnd)
	{
		bool isMemoryExceeded = false;

		char* word = readWord(&isEnd, &isMemoryExceeded);
		if (isMemoryExceeded)
			goto error;

		if (word != nullptr)
		{
			const int indexInArray = getArrayIndexOfAWord(words, totalWordsCount, word, &isMemoryExceeded);
			if (isMemoryExceeded)
				goto error;

			if (indexInArray == NO_INDEX_FOUND)
			{
				const int placementIndex = findPlacementIndex(words, totalWordsCount, word, &isMemoryExceeded);
				if (isMemoryExceeded)
					goto error;

				words = placeWordInArrayByIndex(words, totalWordsCount, placementIndex, word, &isMemoryExceeded);
				if (isMemoryExceeded)
					goto error;

				counts = placeCountValueByIndex(counts, totalWordsCount, placementIndex, &isMemoryExceeded);
				if (isMemoryExceeded)
					goto error;
				++totalWordsCount;
			}
			else
			{
				++counts[indexInArray];
			}
		}
	}

	printCounts(words, counts, totalWordsCount);

	free(words);
	free(counts);
	return 0;

error:
	printf("Error: memory exceeded!\n");
	free(words);
	free(counts);
	return 1;
}

int lowerSymbol(const int symbol)
{
	if ('A' <= symbol && symbol <= 'Z')
	{
		return symbol + REGISTER_DIFFERENCE;
	}

	return symbol;
}

// FIXME: use malloc
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

int getArrayIndexOfAWord(char** array, const int len, const char* str, bool* isError)
{
	char* loweredStr = mallocConvertToLower(str);
	char* loweredComparingStr = nullptr;

	if (loweredStr == nullptr)
	{
		*isError = true;
		return ERROR;
	}

	for (int i = 0; i < len; ++i)
	{
		loweredComparingStr = mallocConvertToLower(array[i]);

		if (loweredStr == nullptr)
		{
			free(loweredStr);
			*isError = true;
			return ERROR;
		}

		if (strcmp(loweredStr, loweredComparingStr) == 0)
		{
			free(loweredStr);
			free(loweredComparingStr);
			return i;
		}
	}

	free(loweredStr);
	free(loweredComparingStr);
	return NO_INDEX_FOUND;
}

int findPlacementIndex(char** array, const int len, const char* str, bool* isError)
{
	int index = 0;
	char* loweredStr = mallocConvertToLower(str);
	char* loweredComparingStr = nullptr;

	if (loweredStr == nullptr)
	{
		*isError = true;
		return ERROR;
	}

	while (index < len)
	{
		loweredComparingStr = mallocConvertToLower(array[index]);

		if (loweredComparingStr == nullptr)
		{
			free(loweredStr);
			*isError = false;
			return ERROR;
		}

		if (strcmp(loweredStr, loweredComparingStr) > 0)
		{
			++index;
		}
		else
		{
			break;
		}
	}

	free(loweredStr);
	free(loweredComparingStr);
	return index;
}

char** placeWordInArrayByIndex(char** array, const int len, const int index, char* str, bool* isError)
{
	char** newArray = realloc(array, (len + 1) * sizeof(char*));

	if (newArray == nullptr)
	{
		free(newArray);
		*isError = true;
		return nullptr;
	}

	for (int i = len; i > index; --i)
	{
		newArray[i] = newArray[i - 1];
	}

	newArray[index] = mallocConvertToLower(str);

	if (newArray[index] == nullptr)
	{
		free(newArray);
		*isError = true;
		return nullptr;
	}

	return newArray;
}

int* placeCountValueByIndex(int* array, const int len, const int index, bool* isError)
{
	int* newArray = realloc(array, (len + 1) * sizeof(int));

	if (newArray == nullptr)
	{
		free(newArray);
		*isError = true;
		return nullptr;
	}

	for (int i = len; i > index; --i)
	{
		newArray[i] = newArray[i - 1];
	}

	newArray[index] = 1;
	return newArray;
}

char* readWord(bool* isEnd, bool* isMemoryExceeded)
{
	char* word = nullptr;
	size_t wordLen = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF && ch != ' ' && ch != '\t')
	{
		char* tmp_ptr = realloc(word, wordLen + 1);

		if (tmp_ptr == nullptr)
		{
			free(word);
			*isMemoryExceeded = true;
			return nullptr;
		}

		word = tmp_ptr;
		word[wordLen++] = (char)ch;
	}

	if (ch == '\n' || ch == EOF)
	{
		*isEnd = true;
	}

	char* tmp_ptr = realloc(word, wordLen);

	if (tmp_ptr == nullptr)
	{
		free(word);
		*isMemoryExceeded = true;
		return nullptr;
	}

	word = tmp_ptr;
	word[wordLen] = '\0';

	return word;
}

void printCounts(char** stringArray, const int* countsArray, const int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%s: %d\n", stringArray[i], countsArray[i]);
	}
}
