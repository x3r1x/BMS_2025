//
// Created by x3r1x on 18.04.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReadString()
{
	char* str = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		char* newStrPtr = realloc(str, len + 1);

		if (newStrPtr == nullptr)
		{
			goto error;
		}

		str = newStrPtr;
		str[len++] = (char)ch;
	}

	char* newStrPtr = realloc(str, len + 1);

	if (newStrPtr == nullptr)
	{
		goto error;
	}

	str = newStrPtr;
	str[len] = '\0';
	return str;

error:
	free(str);
	return nullptr;
}

bool IsFillArraySuccessful(char*** array, const int elementsCount)
{
	*array = calloc(sizeof(char*), elementsCount);

	if (*array == nullptr)
	{
		return false;
	}

	for (int i = 0; i < elementsCount; i++)
	{
		char* str = ReadString();

		if (str == nullptr)
		{
			return false;
		}

		(*array)[i] = str;
	}

	return true;
}

void FreeStringArray(char** array, int arraySize)
{
	if (array == nullptr)
	{
		return;
	}

	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] != nullptr)
		{
			free(array[i]);
		}
		else
		{
			return;
		}
	}

	free(array);
}

void PrintArray(char** array, const int elementsCount)
{
	if (array == nullptr)
	{
		return;
	}

	for (int i = 0; i < elementsCount; i++)
	{
		if (array[i] == nullptr)
		{
			return;
		}

		printf("%s\n", array[i]);
	}
}

int cmp(const void* a, const void* b)
{
	const char* s1 = *(const char**)a;
	const char* s2 = *(const char**)b;

	return strcmp(s1, s2);
}

int main()
{
	int N;
	char** array = nullptr;

	if (scanf("%d", &N) != 1)
	{
		printf("Error: wrong input!\n");
		return 1;
	}

	getchar();

	if (!IsFillArraySuccessful(&array, N))
	{
		FreeStringArray(array, N);
		return 1;
	}

	qsort(array, N, sizeof(char*), cmp);

	PrintArray(array, N);
	FreeStringArray(array, N);
}