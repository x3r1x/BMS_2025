//
// Created by x3r1x on 21.02.2026.
//

#include <stdio.h>

//TODO: why constexpr?
constexpr int ROWS_COUNT = 12;
constexpr int COLUMNS_COUNT = 12;

void readField(int field[ROWS_COUNT][COLUMNS_COUNT]);
void fillFieldWithDots(int field[ROWS_COUNT][COLUMNS_COUNT]);
void edgeNewField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT]);
void printField(int field[ROWS_COUNT][COLUMNS_COUNT]);

int main(void)
{
    int inField[ROWS_COUNT][COLUMNS_COUNT];
    int edgedField[ROWS_COUNT][COLUMNS_COUNT];

    readField(inField);

    fillFieldWithDots(edgedField);
    edgeNewField(inField, edgedField);

    printf("Output:\n");
    printField(edgedField);
}

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

void edgeNewField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            if (inField[i][j] != '#')
            {
                continue;
            }

            const bool isUpperEdged = inField[i - 1][j - 1] == '.' || inField[i - 1][j] == '.' || inField[i - 1][j + 1] == '.';
            const bool isLineEdged = inField[i][j - 1] == '.' || inField[i][j + 1] == '.';
            const bool isLowerEdged = inField[i + 1][j - 1] == '.' || inField[i + 1][j] == '.' || inField[i + 1][j + 1] == '.';
            //FIXME: decompose a condition by variables
            if (i == 0 || i == ROWS_COUNT - 1 || j == 0 || j == COLUMNS_COUNT - 1 || isUpperEdged || isLineEdged || isLowerEdged)
            {
                outField[i][j] = '#';
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