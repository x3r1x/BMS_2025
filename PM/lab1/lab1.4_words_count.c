//
// Created by x3r1x on 11.02.2026.
//

#include <stdio.h>

//код 0 - 48, код 9 - 57
//код a - 97, код z - 122
//код A - 65, код Z - 90

int main(void)
{
    int c;
    int count = 0;
    bool isInsideAWord = false;

    while ((c = getchar()) != EOF)
    {
        if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
        {
            if (!isInsideAWord)
            {
                isInsideAWord = true;
                ++count;
            }
        }
        else
        {
            isInsideAWord = false;
        }
    }

    printf("%d\n", count);
}