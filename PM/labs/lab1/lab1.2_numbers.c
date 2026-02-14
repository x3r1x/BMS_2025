//
// Created by x3r1x on 07.02.2026.
//

#include <stdio.h>

int main(void)
{
    int min = 0, max = 0, even = 0, odd = 0, cnt = 0, sum = 0;
    int  num, elementsFound; //renmame

    while ((elementsFound = scanf("%d", &num)) == 1 || getchar() != EOF)
    {
        if (elementsFound == 1)
        {
            if (cnt == 0)
            {
                min = num;
                max = num;
            }
            else
            {
                if (min > num)
                {
                    min = num;
                }

                if (max < num)
                {
                    max = num;
                }
            }

            if (num % 2 == 0)
            {
                even += 1;
            }
            else
            {
                odd += 1;
            }

            cnt += 1;
            sum += num;
        }
    }

    printf("\nCount: %d\nSum: %d\n", cnt, sum);
    if (cnt != 0)
    {
        printf("Min: %d\nMax: %d\nEven: %d\nOdd: %d\n", min, max, even, odd);
    }
}