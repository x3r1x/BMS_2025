//
// Created by x3r1x on 08.02.2026.
//

#include <stdio.h>

int main(void)
{
    int lowerEdge = 0;
    int upperEdge = 101;
    int ch; //60 = "<", 61 = "=", 62 = ">"

    bool isErrorPrinted = false;
    bool isLiarDetected = false;

    printf("Make up a number from 1 to 100.\n");
    printf("My guess: %d\n", (lowerEdge + upperEdge) / 2);
    while ((ch = getchar()) != 61 && ch != EOF && !isLiarDetected)
    {
        if (ch != 10) //10 = "\n"
        {
            if (!isErrorPrinted)
            {
                if (ch == 60 || ch == 62)
                {
                    if (ch == 60)
                    {
                        upperEdge = (lowerEdge + upperEdge) / 2;

                        if (lowerEdge == (lowerEdge + upperEdge) / 2)
                        {
                            isLiarDetected = true;
                        }
                    }

                    if (ch == 62)
                    {
                        if (upperEdge - 1 == (lowerEdge + upperEdge) / 2)
                        {
                            isLiarDetected = true;
                        }

                        lowerEdge = (lowerEdge + upperEdge) / 2;
                    }

                    if (!isLiarDetected)
                    {
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
        printf("WHY ARE YOU LYING TO ME?!?!?!?!?!?!?");
    }
    else
    {
        printf("Number is guessed!\n");
    }
}
