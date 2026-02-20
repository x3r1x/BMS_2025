//
// Created by x3r1x on 20.02.2026.
//

#include <stdio.h>

constexpr int ROWS_COUNT = 10;
constexpr int COLUMNS_COUNT = 10;

void readField(int field[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            field[i][j] = getchar();
        }

        getchar();
    }
}

void fillFieldWithDots(int field[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            field[i][j] = '.';
        }
    }
}

void normalizeNewField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            if (inField[i][j] == '#')
            {
                outField[i][j] = '#';

                if (i - 1 >= 0) outField[i - 1][j] = '#';
                if (i + 1 < ROWS_COUNT) outField[i + 1][j] = '#';
                if (j - 1 >= 0) outField[i][j - 1] = '#';
                if (j + 1 < COLUMNS_COUNT) outField[i][j + 1] = '#';
            }
        }
    }
}

void printField(int field[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            putchar(field[i][j]);
        }

        putchar('\n');
    }
}

int main(void)
{
    int inField[ROWS_COUNT][COLUMNS_COUNT];
    int normalizedField[ROWS_COUNT][COLUMNS_COUNT];

    readField(inField);

    fillFieldWithDots(normalizedField);
    normalizeNewField(inField, normalizedField);

    printf("Output:\n");

    printField(normalizedField);
}