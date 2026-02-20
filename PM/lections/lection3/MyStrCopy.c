//
// Created by x3r1x on 17.02.2026.
//

#include <stdio.h>

void MyStrCopy(char dest[], const char src[])
{
    int i = 0;

    while ((dest[i] = src[i]) != '\0')
    {
        i++;
    }
}

int main()
{
    char src[] = "Hello!";
    char dst[10];
    MyStrCopy(dst, src);
    puts(dst);
}