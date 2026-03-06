//
// Created by x3r1x on 05.03.2026.
//

#include <stdio.h>

typedef struct
{
	int day;
	int month;
	int year;
} Date;

constexpr int DATE_ARRAY_SIZE = 10;
constexpr int JANUARY = 1;
constexpr int FEBRUARY = 2;
constexpr int MARCH = 3;
constexpr int APRIL = 4;
constexpr int MAY = 5;
constexpr int JUNE = 6;
constexpr int JULY = 7;
constexpr int AUGUST = 8;
constexpr int SEPTEMBER = 9;
constexpr int OCTOBER = 10;
constexpr int NOVEMBER = 11;
constexpr int DECEMBER = 12;

bool isDateCorrect(Date date);
int getPlacementIndex(Date array[DATE_ARRAY_SIZE], int len, Date date);
void placeDateInArray(Date array[DATE_ARRAY_SIZE], int len, Date date, int index);
void printDateArray(Date array[DATE_ARRAY_SIZE], int len);

int main()
{
	int N;
	int currentPlacedDates = 0;
	Date dateArray[DATE_ARRAY_SIZE];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		Date currentDate;
		scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);

		if (!isDateCorrect(currentDate))
		{
			printf("Error: incorrect date %d %d %d!\n", currentDate.day, currentDate.month, currentDate.year);
			return 1;
		}

		int placementIndex = getPlacementIndex(dateArray, currentPlacedDates, currentDate);
		placeDateInArray(dateArray, currentPlacedDates++, currentDate, placementIndex);
	}

	printDateArray(dateArray, N);
}

bool isDateCorrect(const Date date)
{
	switch (date.month)
	{
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER:
		return 0 <= date.day && date.day <= 31;
	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		return 0 <= date.day && date.day <= 30;
	case FEBRUARY:
		if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
		{
			return 0 <= date.day && date.day <= 29;
		}

		return 0 <= date.day && date.day <= 28;

	default:
		return false;
	}
}

int getPlacementIndex(Date array[DATE_ARRAY_SIZE], const int len, const Date date)
{
	int index = 0;
	bool isFound = false;

	while (index < len && !isFound)
	{
		if (date.year > array[index].year
			|| (date.year == array[index].year && date.month > array[index].month)
			|| (date.year == array[index].year && date.month == array[index].month && date.day > array[index].day))
		{
			index++;
		}
		else
		{
			isFound = true;
		}
	}

	return index;
}

void placeDateInArray(Date array[DATE_ARRAY_SIZE], int len, Date date, int index)
{
	for (int i = len; i > index; i--)
	{
		array[i] = array[i - 1];
	}

	array[index] = date;
}

void printDateArray(Date array[DATE_ARRAY_SIZE], const int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d %d %d\n", array[i].day, array[i].month, array[i].year);
	}
}