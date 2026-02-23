//
// Created by x3r1x on 19.02.2026.
//

#include <stdio.h>

constexpr int ARRAY_SIZE = 10;

int readArrayAndCountSum(int* sum, int len, int* numbersArray);
void printElementsGreaterThenAvg(int sum, int len, const int* numbersArray);

int main(void)
{
    int numbersCount;
    int sum;
    int numbers[ARRAY_SIZE];

    if (scanf("%d", &numbersCount) != 1)
    {
        printf("Wrong input found!\n");
        return 1;
    }

    if (numbersCount > ARRAY_SIZE)
    {
        printf("Numbers limit exceeded!\n");
        return 1;
    }

    if (readArrayAndCountSum(&sum, numbersCount, numbers) != 0)
    {
        printf("Wrong input found!\n");
        return 1;
    }

    printElementsGreaterThenAvg(sum, numbersCount, numbers);
}

int readArrayAndCountSum(int* sum, const int len, int* numbersArray)
{
    for (int i = 0; i < len; ++i)
    {
        if (scanf("%d", &numbersArray[i]) != 1)
        {
            return 1;
        }
        *sum += numbersArray[i];
    }

    return 0;
}

void printElementsGreaterThenAvg(const int sum, const int len, const int* numbersArray)
{
    for (int i = 0; i < len; ++i)
    {
        if (numbersArray[i] * len > sum)
        {
            printf("%d ", numbersArray[i]);
        }
    }
}