//
// Created by x3r1x on 08.02.2026.
//

#include <stdio.h>

int main(void)
{
    int lowerEdge = 0;
    int upperEdge = 101;
    int ch;

    bool isErrorPrinted = false;
    bool isLiarDetected = false;

    printf("Make up a number from 1 to 100.\n");
    printf("My guess: %d\n", (lowerEdge + upperEdge) / 2);

    while ((ch = getchar()) != '=' && ch != EOF && !isLiarDetected)
    {
        if (ch != '\n')
        {
            if (!isErrorPrinted)
            {
                if (ch == '<')
                {
                    upperEdge = (lowerEdge + upperEdge) / 2;

                    if (lowerEdge == (lowerEdge + upperEdge) / 2)
                    {
                        isLiarDetected = true;
                    }
                    else
                    {
                        printf("My guess: %d\n", (lowerEdge + upperEdge) / 2);
                    }
                }
                else if (ch == '>')
                {
                    if (upperEdge - 1 == (lowerEdge + upperEdge) / 2)
                    {
                        isLiarDetected = true;
                    }
                    else
                    {
                        lowerEdge = (lowerEdge + upperEdge) / 2;
                        printf("My guess: %d\n", (lowerEdge + upperEdge) / 2);
                    }
                }
                else
                {
                    isErrorPrinted = true;
                    printf("Incorrect input! Write rather your number is <, > or =\n");
                }
            }
        }
        else
        {
            isErrorPrinted = false;
        }
    }

    if (ch == EOF)
    {
        printf("Unfortunately, you didn't finish guessing the number :(\n");
    }
    else if (isLiarDetected)
    {
        printf("WHY ARE YOU LYING TO ME?!?!?!?!?!?!?\n");
    }
    else
    {
        printf("Number is guessed!\n");
    }
}
