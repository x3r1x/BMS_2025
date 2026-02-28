//
// Created by x3r1x on 28.02.2026.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *ReadString(void)
{
    char* s = nullptr;
    size_t len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        char *tmp = realloc(s, len + 1);
        if (tmp == nullptr)
            goto error;
        s = tmp;
        s[len++] = (char)ch;
    }

    char *tmp = realloc(s, len + 1);
    if (tmp == nullptr)
        goto error;

    s = tmp;
    s[len] = '\0';
    return s;

    error:
        free(s);
        return nullptr;
}

int main(void)
{
    char* str = ReadString();

    printf("%s\n", str);
}