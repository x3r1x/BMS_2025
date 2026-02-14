//
// Created by x3r1x on 07.02.2026.
//

#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        printf("%d", c);
    }

    puts("goodbye");
    return 0;
}