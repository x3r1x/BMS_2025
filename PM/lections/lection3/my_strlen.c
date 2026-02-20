//
// Created by x3r1x on 17.02.2026.
//

#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char s[])
{
    size_t len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

int main()
{
    constexpr char str[] = "Hello, world!";

    printf("%lu", my_strlen(str));
}