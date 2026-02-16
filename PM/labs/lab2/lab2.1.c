//
// Created by x3r1x on 16.02.2026.
//

#include <stdio.h>

int readNextOperand()
{
    int operand;
    while (scanf("%d", &operand) != 1)
    {
        const int symbol = getchar();

        if (symbol == EOF || symbol == 'q')
        {
            return -1;
        }

        if (symbol == '\n')
        {
            return -2;
        }
    }

    return operand;
}

int readNextOperation()
{
    int operation = getchar();

    while (operation == ' ')
    {
        operation = getchar();
    }

    if (operation == EOF || operation == 'q')
    {
        return -1;
    }

    if (operation == '\n')
    {
        return -2;
    }

    return operation;
}

//mini-calculator
int main(void)
{
    printf("Enter expressions line by line (or q to quit): \n");

    bool isEnd = false;

    while (!isEnd)
    {
        int firstOperand = readNextOperand();
        if (firstOperand == -1)
        {
            isEnd = true;
        }
        int operation = 0;
        int secondOperand = 0;

        bool isError = false;

        while (firstOperand >= 0 && operation >= 0 && secondOperand >= 0)
        {
            if ((operation = readNextOperation()) >= 0)
            {
                secondOperand = readNextOperand();

                if (secondOperand == -1)
                {
                    isEnd = true;
                }
                else
                {
                    switch (operation)
                    {
                        case '+':
                            firstOperand = firstOperand + secondOperand;
                            break;
                        case '-':
                            firstOperand = firstOperand - secondOperand;
                            break;
                        case '*':
                            firstOperand = firstOperand * secondOperand;
                            break;
                        case '/':
                            if (secondOperand == 0)
                            {
                                printf("Error: division by zero!\n");
                                isError = true;
                                secondOperand = -2;
                            }
                            else
                            {
                                firstOperand = firstOperand / secondOperand;
                            }
                            break;
                        default:
                            printf("Error: unknown operation\n");
                            isError = true;
                            operation = -2;
                    }
                }
            }
            else if (operation == -1)
            {
                isEnd = true;
            }
        }

        if (!isError && !isEnd)
        {
            printf("Answer: %d\n", firstOperand);
        }
    }
}