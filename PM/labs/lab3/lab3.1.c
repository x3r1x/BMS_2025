//
// Created by x3r1x on 23.02.2026.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int REGISTER_DIFFERENCE = 32;

char* readString(bool* isEOF);
char* getNewStringWithoutDividers(const char* inString);
bool isAlphaNumeric(char symbol);
int lowerSymbol(int symbol);
bool isStringPalindrome(const char* inString);

int main(void)
{
    bool isEOF = false;

    while (!isEOF)
    {
        //FIXME: free
        char* str = readString(&isEOF);
        if (isEOF) break;

        if (str == nullptr)
        {
            printf("Error: not enough memory!\n");
            return 1;
        }

        char* strWithoutDividers = getNewStringWithoutDividers(str);
        if (strWithoutDividers == nullptr)
        {
            printf("Error: not enough memory!\n");
            free(str);
            return 1;
        }

        if (isStringPalindrome(strWithoutDividers))
        {
            printf("%s\n", str);
        }

        free(str);
        free(strWithoutDividers);
    }
}

char* readString(bool* isEOF)
{
    char* str = nullptr;
    size_t len = 0;
    int ch;
    *isEOF = false;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        char* newStrPtr = realloc(str, len + 1);

        if (newStrPtr == nullptr)
        {
            goto error;
        }

        str = newStrPtr;
        str[len++] = (char) ch;
    }

    if (ch == EOF)
    {
        *isEOF = true;
        goto error;
    }

    char *newStrPtr = realloc(str, len + 1);

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

bool isAlphaNumeric(const char symbol)
{
    return ('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z') || ('0' <= symbol && symbol <= '9');
}

//FIXME: make malloc
char *getNewStringWithoutDividers(const char* inString)
{
    char* outString = nullptr;
    size_t outStringLength = 0;
    const size_t inStringLen = strlen(inString);

    for (int i = 0; i <= inStringLen - 1; ++i)
    {
        if (isAlphaNumeric(inString[i]))
        {
            char *newStrPtr = realloc(outString, outStringLength + 1);

            if (newStrPtr == nullptr)
            {
                free(outString);
                return nullptr;
            }

            outString = newStrPtr;
            outString[outStringLength++] = inString[i];
        }
    }

    char *newStrPtr = realloc(outString, outStringLength + 1);

    if (newStrPtr == nullptr)
    {
        free(outString);
        return nullptr;
    }

    outString = newStrPtr;
    outString[outStringLength] = '\0';
    return outString;
}

int lowerSymbol(const int symbol)
{
    if ('A' <= symbol && symbol <= 'Z')
    {
        return symbol + REGISTER_DIFFERENCE;
    }

    return symbol;
}

bool isStringPalindrome(const char *inString)
{
    const size_t inStringLen = strlen(inString);

    for (int i = 0, j = inStringLen - 1; i < j; ++i, --j)
    {
        if (lowerSymbol(inString[i]) != lowerSymbol(inString[j]))
        {
            return false;
        }
    }

    return true;
}
