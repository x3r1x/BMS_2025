//
// Created by x3r1x on 21.02.2026.
//

#include <stdio.h>

constexpr int ROWS_COUNT = 12;
constexpr int COLUMNS_COUNT = 12;

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

void transformNewField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            if (inField[i][j] == '#')
            {
                if (i == 0 || i == ROWS_COUNT - 1 || j == 0 || j == COLUMNS_COUNT - 1 || inField[i - 1][j - 1] == '.' ||
                    inField[i - 1][j] == '.' || inField[i - 1][j + 1] == '.' || inField[i][j + 1] == '.' ||
                    inField[i + 1][j + 1] == '.'  || inField[i][j + 1] == '.' || inField[i - 1][j] == '.' ||
                    inField[i][j - 1] == '.')
                {
                    outField[i][j] = '#';
                }
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
    int transformedField[ROWS_COUNT][COLUMNS_COUNT];

    readField(inField);

    fillFieldWithDots(transformedField);
    transformNewField(inField, transformedField);

    printf("Output:\n");
    printField(transformedField);
}
