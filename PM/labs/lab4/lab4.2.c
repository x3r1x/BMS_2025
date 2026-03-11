//
// Created by x3r1x on 07.03.2026.
//

#include <stdio.h>

constexpr int TOWN_ARRAY_SIZE = 10;
constexpr int MAX_NAME_SIZE = 20;

typedef struct
{
	int x;
	int y;
} Coordinates ;

typedef struct
{
	char name[MAX_NAME_SIZE];
	Coordinates coordinates;
	int distanceToCustomer;
} Town;

void ReadTownInfos(Town array[TOWN_ARRAY_SIZE], int len, bool* isError);
int CalculateTownDistancesAndGetMin(Town array[TOWN_ARRAY_SIZE], int len, Coordinates coordinates);
void PrintClosestTownInfos(Town array[TOWN_ARRAY_SIZE], int len, int minDistance);

int main()
{
	int n;

	bool isError;
	Town townArray[TOWN_ARRAY_SIZE];
	Coordinates customerCoordinates;

	if (scanf("%d", &n) != 1)
	{
		printf("Error: unexpected input!\n");
		return 1;
	}

	ReadTownInfos(townArray, n, &isError);

	if (isError || scanf("%d %d", &customerCoordinates.x, &customerCoordinates.y) != 2)
	{
		printf("Error: unexpected input!");
		return 1;
	}

	const int minDistance = CalculateTownDistancesAndGetMin(townArray, n, customerCoordinates);

	PrintClosestTownInfos(townArray, n, minDistance);
}

void ReadTownInfos(Town array[TOWN_ARRAY_SIZE], const int len, bool* isError)
{
	*isError = false;

	for (int i = 0; i < len; i++)
	{
		if (scanf("%d %d %s", &array[i].coordinates.x, &array[i].coordinates.y, array[i].name) != 3)
		{
			*isError = true;
			return;
		}
	}
}

int Module(const int x)
{
	if (x >= 0) return x;

	return -x;
}

int CalculateTownDistancesAndGetMin(Town array[TOWN_ARRAY_SIZE], int len, Coordinates coordinates)
{
	int minDistance = 0;

	for (int i = 0; i < len; i++)
	{
		array[i].distanceToCustomer = Module(array[i].coordinates.x - coordinates.x) + Module(array[i].coordinates.y - coordinates.y);

		if (array[i].distanceToCustomer < minDistance || i == 0)
		{
			minDistance = array[i].distanceToCustomer;
		}
	}

	return minDistance;
}

void PrintClosestTownInfos(Town array[TOWN_ARRAY_SIZE], const int len, const int minDistance)
{
	for (int i = 0; i < len; i++)
	{
		if (array[i].distanceToCustomer == minDistance)
		{
			printf("%s (%d, %d) distance = %d\n", array[i].name, array[i].coordinates.x, array[i].coordinates.y, array[i].distanceToCustomer);
		}
	}
}