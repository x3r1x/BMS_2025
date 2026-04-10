//
// Created by x3r1x on 21.03.2026.
//

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int NAME_SIZE = 51;
constexpr int SYMBOLS_PER_DUMP = 16;

struct Employee
{
	int birthYear;
	short birthMonth;
	char birthDay;
	char name[NAME_SIZE]; // Имя (50 символов максимум)
	int64_t salary;
};

void PrintDump(const uint8_t* data, size_t size);
void StringResearch();
void DataResearch();

int main(void)
{
	StringResearch();
	DataResearch();
}

void PrintDump(const uint8_t* data, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%02X ", data[i]);
	}

	printf("\n");
}

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

void PrintAddressInfo(const char* str, const size_t iteration)
{
	for (int j = 0; j < SYMBOLS_PER_DUMP; j++)
	{
		printf("%02X ", str[iteration * SYMBOLS_PER_DUMP + j]);

		if (j % 8 == 7)
		{
			printf("| ");
		}
	}
}

void PrintStringInfo(const char* str, const size_t iteration)
{
	for (int j = 0; j < SYMBOLS_PER_DUMP; j++)
	{
		if (str[iteration * SYMBOLS_PER_DUMP + j] == 0)
		{
			break;
		}

		if (32 <= str[iteration * SYMBOLS_PER_DUMP + j] && str[iteration * SYMBOLS_PER_DUMP + j] <= 127)
		{
			printf("%c", str[iteration * SYMBOLS_PER_DUMP + j]);
		}
		else
		{
			printf(".");
		}
	}
}

void StringResearch()
{
	char* str = ReadString();
	size_t iterations = strlen(str) / SYMBOLS_PER_DUMP;

	if (strlen(str) % SYMBOLS_PER_DUMP != 0)
	{
		iterations++;
	}

	for (int i = 0; i < iterations; i++)
	{
		printf("%p: ", str + i * SYMBOLS_PER_DUMP);

		PrintAddressInfo(str, i);
		PrintStringInfo(str, i);

		printf("\n");
	}

	free(str);
}

void DataResearch()
{
	int a[6];
	constexpr char str[] = "A quick brown fox jumps over the lazy dog";
	struct Employee employee;

	if (scanf("%d %d %d %d %d %d\n", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) != 6)
	{
		printf("Error: incorrect input!\n");
		return;
	}

	if (scanf("%d %hu %c\n", &employee.birthYear, &employee.birthMonth, &employee.birthDay) != 3)
	{
		printf("Error: incorrect input!\n");
		return;
	}

	fgets(employee.name, 51, stdin);

	if (scanf("%ld", &employee.salary) != 1)
	{
		printf("Error: incorrect input!\n");
		return;
	}

	printf("Dump of int array:\n");
	PrintDump((const uint8_t*)&a, sizeof(a));

	printf("Dump of string:\n");
	PrintDump((const uint8_t*)&str, sizeof(str));

	printf("Dump of Employee: \n");
	PrintDump((const uint8_t*)&employee, sizeof(employee));
}