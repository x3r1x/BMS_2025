//
// Created by x3r1x on 19.02.2026.
//

#include <stdio.h>

constexpr int ARRAY_SIZE = 100;

int readArray(const int len, int* numbersArray)
{
    for (int i = 0; i < len; ++i)
    {
        if (scanf("%d", &numbersArray[i]) != 1)
        {
            return 1;
        }
    }

    return 0;
}

void printReversedArray(const int len, const int* numbersArray)
{
    for (int i = len - 1; i >= 0; --i)
    {
        if (i != 0)
        {
            printf("%d ", numbersArray[i]);
        }
        else
        {
            printf("%d\n", numbersArray[0]);
        }
    }
}

int main(void)
{
    int numbersCount;
    int numbers[ARRAY_SIZE];

    if (scanf("%d", &numbersCount) != 1)
    {
        printf("Wrong input found!\n");
        return 1;
    }

    if (readArray(numbersCount, numbers) != 0)
    {
        printf("Wrong input found!\n");
        return 1;
    }

    printReversedArray(numbersCount, numbers);
}
