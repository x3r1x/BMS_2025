//
// Created by x3r1x on 04.04.2026.
//

#include <stdint.h>
#include <stdio.h>

struct Employee
{
	int birthYear;
	short birthMonth;
	char birthDay;
	char name[51]; // Имя (50 символов максимум)
	int64_t salary;
};

int main()
{
	char str[51];
	struct Employee e;

	fgets(e.name, 51, stdin);
	printf("%s", e.name);
}