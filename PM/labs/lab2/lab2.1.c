//
// Created by x3r1x on 14.02.2026.
//

#include <stdio.h>

const int SYMBOL_PLUS = 43;
const int SYMBOL_MINUS = 45;
const int SYMBOL_MULTIPLICATION = 42;
const int SYMBOL_DIVISION = 47;

int main(void)
{
    int firstOperand, secondOperand;
    printf("Enter expression: ");

    scanf("%d", &firstOperand);
    getchar();
    int operation = getchar();
    getchar();
    scanf("%d", &secondOperand);

    switch (operation)
    {
        case SYMBOL_PLUS:    // "+"
            printf("Result: %d", firstOperand + secondOperand);
            break;
        case SYMBOL_MINUS:  // "-"
            printf("Result: %d", firstOperand - secondOperand);
            break;
        case SYMBOL_MULTIPLICATION: // "*"
            printf("Result: %d", firstOperand * secondOperand);
            break;
        case SYMBOL_DIVISION: // "/"
            if (secondOperand == 0)
            {
                printf("Error: division by zero!");
                return 2;
            }

            printf("Result: %d", firstOperand / secondOperand);
            break;
        default:
            printf("Error: unknown operation");
            return 1;
    }
}