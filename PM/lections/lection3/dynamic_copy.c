//
// Created by x3r1x on 17.02.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char source[] = "Hello, dynamic world!";

    const size_t len = strlen(source);

    char *copy = malloc(len + 1);
    if (copy == NULL)
    {
        return 1;
    }

    strcpy(copy, source);
    printf("%s\n", copy);
    free(copy);
}
