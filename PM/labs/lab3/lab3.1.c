//
// Created by x3r1x on 23.02.2026.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int REGISTER_DIFFERENCE = 32;

char* readString(bool* isEOF);
char* getNewStringWithoutDividers(const char* inString);
bool isStringPalindrome(const char* inString);

int main(void)
{
    bool isEOF = false;
    while (!isEOF)
    {
        const char* str = readString(&isEOF);

        if (str != nullptr)
        {
            str = getNewStringWithoutDividers(str);

            if (isStringPalindrome(str))
            {
                printf("%s\n", str);
            }
        }
        else if (!isEOF) printf("Could not read a string: not enough memory!\n");
    }
}

char* readString(bool* isEOF)
{
    char* str = nullptr;
    size_t len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        char *tmp_ptr = realloc(str, len + 1);

        if (tmp_ptr == nullptr)
        {
            free(str);
            return nullptr;
        }

        str = tmp_ptr;
        str[len++] = (char)ch;
    }

    if (ch == EOF)
    {
        *isEOF = true;
        return nullptr;
    }

    str[len] = '\0';
    return str;
}

char* getNewStringWithoutDividers(const char* inString)
{
    char* outString = nullptr;
    size_t outStringLength = 0;

    for (int i = 0; i <= strlen(inString) - 1; ++i)
    {
        if (('a' <= inString[i] && inString[i] <= 'z') || ('A' <= inString[i] && inString[i] <= 'Z') ||
            ('0' <= inString[i] && inString[i] <= '9'))
        {
            char* tmp_ptr = realloc(outString, outStringLength + 1);

            if (tmp_ptr == nullptr)
            {
                free(outString);
                return nullptr;
            }

            outString = tmp_ptr;
            outString[outStringLength++] = inString[i];
        }
    }

    outString[outStringLength] = '\0';
    return outString;
}

bool isStringPalindrome(const char* inString)
{
    for (int i = 0, j = strlen(inString) - 1; i < j; ++i, --j)
    {
        if (inString[i] != inString[j] && inString[i] - inString[j] != REGISTER_DIFFERENCE && inString[j] - inString[i] != REGISTER_DIFFERENCE)
        {
            return false;
        }
    }

    return true;
}