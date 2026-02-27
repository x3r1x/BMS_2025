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
char* toLower(const char* inString);
int getArrayIndexOfAWord(char** array, int len, const char* str, bool* isError);
int findPlacementIndex(char** array, int len, const char* str);
char** placeWordInArrayByIndex(char** array, int len, int index, char* str, bool* isError);
int* placeCountValueByIndex(int* array, int len, int index, bool *isError);
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
        if (isMemoryExceeded) goto error;

        if (word != nullptr)
        {
            const int indexInArray = getArrayIndexOfAWord(words, totalWordsCount, word, &isMemoryExceeded);
            if (isMemoryExceeded) goto error;

            if (indexInArray == NO_INDEX_FOUND)
            {
                const int placementIndex = findPlacementIndex(words, totalWordsCount, word);
                words = placeWordInArrayByIndex(words, totalWordsCount, placementIndex, word, &isMemoryExceeded);
                if (isMemoryExceeded) goto error;

                counts = placeCountValueByIndex(counts, totalWordsCount, placementIndex, &isMemoryExceeded);
                if (isMemoryExceeded) goto error;
                ++totalWordsCount;
            }
            else
            {
                ++counts[indexInArray];
            }
        }
    }

    printCounts(words, counts, totalWordsCount);

    return 0;

    error:
        printf("Error: memory exceeded!\n");
        free(words);
        free(counts);
        return 1;
}

char* toLower(const char* inString)
{
    char* newStr = nullptr;
    size_t newStrLen = 0;

    for (int i = 0; i < strlen(inString); ++i)
    {
        char* tmp_ptr = realloc(newStr, newStrLen + 1);

        if (tmp_ptr == nullptr)
        {
            free(newStr);
            return nullptr;
        }

        newStr = tmp_ptr;
        int ch = inString[i];

        if ('A' <= inString[i] && inString[i] <= 'Z')
        {
            ch += REGISTER_DIFFERENCE;
        }

        newStr[newStrLen++] = (char) ch;
    }

    newStr[newStrLen] = '\0';
    return newStr;
}

int getArrayIndexOfAWord(char** array, const int len, const char* str, bool* isError)
{
    const char* loweredStr = toLower(str);

    if (loweredStr == nullptr)
    {
        *isError = true;
        return ERROR;
    }

    for (int i = 0; i < len; ++i)
    {
        if (strcmp(loweredStr, toLower(array[i])) == 0)
        {
            return i;
        }
    }

    return NO_INDEX_FOUND;
}

int findPlacementIndex(char** array, const int len, const char* str)
{
    int index = 0;

    while (index < len && strcmp(toLower(str), toLower(array[index])) > 0)
    {
        ++index;
    }

    return index;
}

char** placeWordInArrayByIndex(char** array, const int len, const int index, char* str, bool* isError)
{
    char** newArray = realloc(array, len + 1);

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

    newArray[index] = toLower(str);
    return newArray;
}

int* placeCountValueByIndex(int* array, const int len, const int index, bool *isError)
{
    int* newArray = realloc(array, len + 1);

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

    if (word != nullptr)
    {
        word[wordLen] = '\0';
    }

    if (ch == '\n' || ch == EOF)
    {
        *isEnd = true;
    }

    return word;
}

void printCounts(char **stringArray, const int* countsArray, const int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s: %d\n", stringArray[i], countsArray[i]);
    }
}