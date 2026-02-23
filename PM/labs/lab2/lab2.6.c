//
// Created by x3r1x on 21.02.2026.
//

#include <stdio.h>

constexpr int ROWS_COUNT = 8;
constexpr int COLUMNS_COUNT = 8;

constexpr int WHITE_ROOK = 'R';
constexpr int WHITE_KNIGHT = 'N';
constexpr int WHITE_MARK = '1';

constexpr int BLACK_ROOK = 'r';
constexpr int BLACK_KNIGHT = 'n';
constexpr int BLACK_MARK = '0';

void readField(int field[ROWS_COUNT][COLUMNS_COUNT]);
void copyField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT]);
void markKnightAttack(int whiteAttackField[ROWS_COUNT][COLUMNS_COUNT], int blackAttackField[ROWS_COUNT][COLUMNS_COUNT]);
void markRookAttack(const int originalField[ROWS_COUNT][COLUMNS_COUNT], int whiteAttackField[ROWS_COUNT][COLUMNS_COUNT], int blackAttackField[ROWS_COUNT][COLUMNS_COUNT]);
void printField(int field[ROWS_COUNT][COLUMNS_COUNT]);

int main(void)
{
    int inField[ROWS_COUNT][COLUMNS_COUNT];
    int whiteAttackedField[ROWS_COUNT][COLUMNS_COUNT];
    int blackAttackedField[ROWS_COUNT][COLUMNS_COUNT];

    readField(inField);
    copyField(inField, whiteAttackedField);
    copyField(inField, blackAttackedField);

    markKnightAttack(whiteAttackedField, blackAttackedField);
    markRookAttack(inField, whiteAttackedField, blackAttackedField);

    printf("White attacks:\n");
    printField(whiteAttackedField);
    printf("Black attacks:\n");
    printField(blackAttackedField);
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

void copyField(const int inField[ROWS_COUNT][COLUMNS_COUNT], int outField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            outField[i][j] = inField[i][j];
        }
    }
}

void markKnightAttack(int whiteAttackField[ROWS_COUNT][COLUMNS_COUNT], int blackAttackField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            //TODO: simplify
            if (whiteAttackField[i][j] == WHITE_KNIGHT)
            {
                if (i + 2 < ROWS_COUNT && j + 1 < COLUMNS_COUNT && !('A' <= whiteAttackField[i + 2][j + 1] && whiteAttackField[i + 2][j + 1] <= 'Z')) whiteAttackField[i + 2][j + 1] = WHITE_MARK;
                if (i + 2 < ROWS_COUNT && j - 1 >= 0 && !('A' <= whiteAttackField[i + 2][j - 1] && whiteAttackField[i + 2][j - 1] <= 'Z')) whiteAttackField[i + 2][j - 1] = WHITE_MARK;
                if (i - 2 >= 0 && j + 1 < COLUMNS_COUNT && !('A' <= whiteAttackField[i - 2][j + 1] && whiteAttackField[i - 2][j + 1] <= 'Z')) whiteAttackField[i - 2][j + 1] = WHITE_MARK;
                if (i - 2 >= 0 && j - 1 >= 0 && !('A' <= whiteAttackField[i - 2][j - 1] && whiteAttackField[i - 2][j - 1] <= 'Z')) whiteAttackField[i - 2][j - 1] = WHITE_MARK;
                if (i + 1 < ROWS_COUNT && j + 2 < COLUMNS_COUNT && !('A' <= whiteAttackField[i + 1][j + 2] && whiteAttackField[i + 1][j + 2] <= 'Z')) whiteAttackField[i + 1][j + 2] = WHITE_MARK;
                if (i + 1 < ROWS_COUNT && j - 2 >= 0 && !('A' <= whiteAttackField[i + 1][j - 2] && whiteAttackField[i + 1][j - 2] <= 'Z')) whiteAttackField[i + 1][j - 2] = WHITE_MARK;
                if (i - 1 >= 0 && j + 2 < COLUMNS_COUNT && !('A' <= whiteAttackField[i - 1][j + 2] && whiteAttackField[i - 1][j + 2] <= 'Z')) whiteAttackField[i - 1][j + 2] = WHITE_MARK;
                if (i - 1 >= 0 && j - 2 >= 0 && !('A' <= whiteAttackField[i - 1][j - 2] && whiteAttackField[i - 1][j - 2] <= 'Z')) whiteAttackField[i - 1][j - 2] = WHITE_MARK;
            }

            if (blackAttackField[i][j] == BLACK_KNIGHT)
            {
                if (i + 2 < ROWS_COUNT && j + 1 < COLUMNS_COUNT && !('a' <= blackAttackField[i + 2][j + 1] && blackAttackField[i + 2][j + 1] <= 'z')) blackAttackField[i + 2][j + 1] = BLACK_MARK;
                if (i + 2 < ROWS_COUNT && j - 1 >= 0 && !('a' <= blackAttackField[i + 2][j - 1] && blackAttackField[i + 2][j - 1] <= 'z')) blackAttackField[i + 2][j - 1] = BLACK_MARK;
                if (i - 2 >= 0 && j + 1 < COLUMNS_COUNT && !('a' <= blackAttackField[i - 2][j + 1] && blackAttackField[i - 2][j + 1] <= 'z')) blackAttackField[i - 2][j + 1] = BLACK_MARK;
                if (i - 2 >= 0 && j - 1 >= 0 && !('a' <= blackAttackField[i - 2][j - 1] && blackAttackField[i - 2][j - 1] <= 'z')) blackAttackField[i - 2][j - 1] = BLACK_MARK;
                if (i + 1 < ROWS_COUNT && j + 2 < COLUMNS_COUNT && !('a' <= blackAttackField[i + 1][j + 2] && blackAttackField[i + 1][j + 2] <= 'z')) blackAttackField[i + 1][j + 2] = BLACK_MARK;
                if (i + 1 < ROWS_COUNT && j - 2 >= 0 && !('a' <= blackAttackField[i + 1][j - 2] && blackAttackField[i + 1][j - 2] <= 'z')) blackAttackField[i + 1][j - 2] = BLACK_MARK;
                if (i - 1 >= 0 && j + 2 < COLUMNS_COUNT && !('a' <= blackAttackField[i - 1][j + 2] && blackAttackField[i - 1][j + 2] <= 'z')) blackAttackField[i - 1][j + 2] = BLACK_MARK;
                if (i - 1 >= 0 && j - 2 >= 0 && !('a' <= blackAttackField[i - 1][j - 2] && blackAttackField[i - 1][j - 2] <= 'z')) blackAttackField[i - 1][j - 2] = BLACK_MARK;
            }
        }
    }
}

void markRookAttack(const int originalField[ROWS_COUNT][COLUMNS_COUNT], int whiteAttackField[ROWS_COUNT][COLUMNS_COUNT], int blackAttackField[ROWS_COUNT][COLUMNS_COUNT])
{
    for (int i = 0; i < ROWS_COUNT; ++i)
    {
        for (int j = 0; j < COLUMNS_COUNT; ++j)
        {
            //TODO: decompose
            if (originalField[i][j] == WHITE_ROOK)
            {
                for (int k = i; k >= 0; --k)
                {
                    if (originalField[k][j] == '.')
                    {
                        whiteAttackField[k][j] = WHITE_MARK;
                    }
                    else
                    {
                        if ('a' <= originalField[k][j] && originalField[k][j] <= 'z')
                        {
                            whiteAttackField[k][j] = WHITE_MARK;
                        }

                        if (k != i) break;
                    }
                }

                for (int k = i; k < ROWS_COUNT; ++k)
                {
                    if (originalField[k][j] == '.')
                    {
                        whiteAttackField[k][j] = WHITE_MARK;
                    }
                    else
                    {
                        if ('a' <= originalField[k][j] && originalField[k][j] <= 'z')
                        {
                            whiteAttackField[k][j] = WHITE_MARK;
                        }

                        if (k != i) break;
                    }
                }

                for (int k = j; k >= 0; --k)
                {
                    if (originalField[i][k] == '.')
                    {
                        whiteAttackField[i][k] = WHITE_MARK;
                    }
                    else
                    {
                        if ('a' <= originalField[i][k] && originalField[i][k] <= 'z')
                        {
                            whiteAttackField[i][k] = WHITE_MARK;
                        }

                        if (k != j) break;
                    }
                }

                for (int k = j; k < COLUMNS_COUNT; ++k)
                {
                    if (originalField[i][k] == '.')
                    {
                        whiteAttackField[i][k] = WHITE_MARK;
                    }
                    else
                    {
                        if ('a' <= originalField[i][k] && originalField[i][k] <= 'z')
                        {
                            whiteAttackField[i][k] = WHITE_MARK;
                        }

                        if (k != j) break;
                    }
                }
            }

            if (originalField[i][j] == BLACK_ROOK)
            {
                for (int k = i; k >= 0; --k)
                {
                    if (originalField[k][j] == '.')
                    {
                        blackAttackField[k][j] = BLACK_MARK;
                    }
                    else
                    {
                        if ('A' <= originalField[k][j] && originalField[k][j] <= 'Z')
                        {
                            blackAttackField[k][j] = BLACK_MARK;
                        }

                        if (k != i) break;
                    }
                }

                for (int k = i; k < ROWS_COUNT; ++k)
                {
                    if (originalField[k][j] == '.')
                    {
                        blackAttackField[k][j] = BLACK_MARK;
                    }
                    else
                    {
                        if ('A' <= originalField[k][j] && originalField[k][j] <= 'Z')
                        {
                            blackAttackField[k][j] = BLACK_MARK;
                        }

                        if (k != i) break;
                    }
                }

                for (int k = j; k >= 0; --k)
                {
                    if (originalField[i][k] == '.')
                    {
                        blackAttackField[i][k] = BLACK_MARK;
                    }
                    else
                    {
                        if ('A' <= originalField[i][k] && originalField[i][k] <= 'Z')
                        {
                            blackAttackField[i][k] = BLACK_MARK;
                        }

                        if (k != j) break;
                    }
                }

                for (int k = j; k < COLUMNS_COUNT; ++k)
                {
                    if (originalField[i][k] == '.')
                    {
                        blackAttackField[i][k] = BLACK_MARK;
                    }
                    else
                    {
                        if ('A' <= originalField[i][k] && originalField[i][k] <= 'Z')
                        {
                            blackAttackField[i][k] = BLACK_MARK;
                        }

                        if (k != j) break;
                    }
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
            if (field[i][j] == WHITE_MARK || field[i][j] == BLACK_MARK)
            {
                putchar('*');
            }
            else
            {
                putchar(field[i][j]);
            }
        }

        putchar('\n');
    }
}