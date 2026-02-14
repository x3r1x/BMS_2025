//
// Created by x3r1x on 11.02.2026.
//

#include <stdio.h>

int main(void)
{
    int ch;
    int wordCounter = 0;
    bool isInsideAWord = false;

    while ((ch = getchar()) != EOF)
    {
        if (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
        {
            if (!isInsideAWord)
            {
                isInsideAWord = true;
                ++wordCounter;
            }
        }
        else
        {
            isInsideAWord = false;
        }
    }

    printf("%d\n", wordCounter);
}