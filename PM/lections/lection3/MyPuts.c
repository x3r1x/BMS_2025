//
// Created by x3r1x on 17.02.2026.
//

#include <stdio.h>

void MyPuts(const char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
    }

    putchar('\n');
}

int main()
{
    constexpr char str[] = "Hello, world!";

    MyPuts(str);
}