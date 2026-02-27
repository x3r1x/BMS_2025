//
// Created by x3r1x on 24.02.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int STRING_SAMPLING_ARRAY_SIZE = 3;
constexpr int REGISTER_DIFFERENCE = 32;

char* readString();
char* toLower(const char* inString);
void placeStringInSamplingArray(char* simplingArray[STRING_SAMPLING_ARRAY_SIZE], char* str);
void printArray(char* array[STRING_SAMPLING_ARRAY_SIZE]);

int main(void)
{
    int N;
    char* stringSamplingArray[STRING_SAMPLING_ARRAY_SIZE] = {nullptr, nullptr, nullptr};

    if (scanf("%d", &N) != 1)
    {
        printf("Error: Wrong input!\n");
        return 1;
    }

    getchar();

    for (int i = 0; i < N; ++i)
    {
        char *str = readString();

        if (str == nullptr)
        {
            printf("Error: Not enough memory\n");
            return 1;
        }

        placeStringInSamplingArray(stringSamplingArray, str);
    }

    printArray(stringSamplingArray);
}

char* readString()
{
    char* str = nullptr;
    size_t len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        char* tmp_ptr = realloc(str, len + 1);

        if (tmp_ptr == nullptr)
        {
            free(str);
            return nullptr;
        }

        str = tmp_ptr;
        str[len++] = (char) ch;
    }

    str[len] = '\0';
    return str;
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

void placeStringInSamplingArray(char* simplingArray[STRING_SAMPLING_ARRAY_SIZE], char* str)
{
    int index = 0;

    while (index < STRING_SAMPLING_ARRAY_SIZE && simplingArray[index] != nullptr)
    {
        if (strcmp(toLower(str), toLower(simplingArray[index])) < 0)
        {
            ++index;
        }
        else
        {
            break;
        }
    }

    if (simplingArray[index] == nullptr)
    {
        simplingArray[index] = str;
    }

    if (index != STRING_SAMPLING_ARRAY_SIZE)
    {
        for (int i = STRING_SAMPLING_ARRAY_SIZE - 1; i > index; --i)
        {
            simplingArray[i] = simplingArray[i - 1];
        }

        simplingArray[index] = str;
    }
}

void printArray(char* array[STRING_SAMPLING_ARRAY_SIZE])
{
    for (int i = 0; i < STRING_SAMPLING_ARRAY_SIZE; ++i)
    {
        if (array[i] != nullptr)
        {
            printf("%s\n", array[i]);
        }
    }
}