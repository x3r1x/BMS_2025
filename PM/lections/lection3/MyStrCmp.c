//
// Created by x3r1x on 17.02.2026.
//

#include <stdio.h>
#include <string.h>

int MyStrCmp(const char a[], const char b[])
{
    int i = 0;

    while (a[i] == b[i])
    {
        if (a[i] == '\0')
        {
            return 0; //строки закончились -> равны
        }

        i++;
    }

    return (unsigned char)a[i] - (unsigned char)b[i];
}

int main()
{
    constexpr  char s1[] = "pear";
    constexpr char s2[] = "apple";
    printf("%d\n", MyStrCmp(s1, s2));
    printf("%d\n", strcmp(s1, s2));
}