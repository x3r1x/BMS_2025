//
// Created by x3r1x on 23.02.2026.
//


#include <stdio.h>
#include <string.h>

constexpr int STRING_SIZE = 100;
constexpr int REGISTER_DIFFERENCE = 32;

void deleteNewLineSymbol(char inString[STRING_SIZE]);
void copyStringWithoutDividers(char inString[STRING_SIZE], char outString[STRING_SIZE]);
bool isStringPalindrome(char inString[STRING_SIZE]);

int main(void)
{
    char inStr[STRING_SIZE];
    char noDividerStr[STRING_SIZE];

    while (fgets(inStr, sizeof(inStr), stdin) != NULL)
    {
        deleteNewLineSymbol(inStr);
        copyStringWithoutDividers(inStr, noDividerStr);

        if (isStringPalindrome(noDividerStr))
        {
            printf("%s\n", inStr);
        }
    }
}

void deleteNewLineSymbol(char inString[STRING_SIZE])
{
    const size_t length = strlen(inString);

    if (length > 0 && inString[length - 1] == '\n')
    {
        inString[length - 1] = '\0';
    }
}

void copyStringWithoutDividers(char inString[STRING_SIZE], char outString[STRING_SIZE])
{
    int currentOutStringIndex = 0;

    for (int i = 0; i <= strlen(inString) - 1; ++i)
    {
        if (('a' <= inString[i] && inString[i] <= 'z') || ('A' <= inString[i] && inString[i] <= 'Z') ||
            ('0' <= inString[i] && inString[i] <= '9'))
        {
            outString[currentOutStringIndex] = inString[i];

            ++currentOutStringIndex;
        }
    }

    outString[currentOutStringIndex] = '\0';
}

bool isStringPalindrome(char inString[STRING_SIZE])
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