//
// Created by x3r1x on 07.02.2026.
//

#include <stdio.h>

int fib(const int n) {
    int result;

    if (n == 0) {
        result = 0;
    } else if (n == 1) {
        result = 1;
    } else {
        int a = 0;
        int b = 1;
        result = a + b;
        for (int i = 2; i < n; ++i) {
            if (a <= b) {
                a = result;
            } else {
                b = result;
            }

            result = a + b;
        }
    }

    return result;
}

int main(void) {
    int n;

    printf("Введите n-ое число Фибонначи, которое надо вывести! Для завершения программы введите EOF\n");
    if (scanf("%d", &n) != 1) {
        printf("Неверный формат ввода!\n");
        return 1;
    }
    if (n < 0) {
        printf("Число %d меньше нуля, а значит такое число Фибонначи не существует!\n", n);
        return 2;
    }
    printf("%d\n", fib(n));
}
