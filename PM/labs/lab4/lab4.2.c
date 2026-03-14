//
// Created by x3r1x on 07.03.2026.
//

#include <stdio.h>
#include <stdlib.h>

constexpr int TOWN_ARRAY_SIZE = 10;
constexpr int MAX_NAME_SIZE = 20;

typedef struct
{
	int x;
	int y;
} Coordinates;

typedef struct
{
	char name[MAX_NAME_SIZE];
	Coordinates coordinates;
} Town;

bool IsReadTownInfosSuccessful(Town array[TOWN_ARRAY_SIZE], int len);
int CalculateTownDistancesAndGetMin(const Town towns[TOWN_ARRAY_SIZE], int townDistances[TOWN_ARRAY_SIZE], int len, Coordinates coordinates);
void PrintClosestTownInfos(const Town towns[TOWN_ARRAY_SIZE], const int townDistances[TOWN_ARRAY_SIZE], int len, int minDistance);

int main()
{
	int n;

	Town townArray[TOWN_ARRAY_SIZE];
	int townDistances[TOWN_ARRAY_SIZE];
	Coordinates customerCoordinates;

	if (scanf("%d", &n) != 1)
	{
		printf("Error: unexpected input!\n");
		return 1;
	}

	if (!IsReadTownInfosSuccessful(townArray, n) || scanf("%d %d", &customerCoordinates.x, &customerCoordinates.y) != 2)
	{
		printf("Error: unexpected input!");
		return 1;
	}

	const int minDistance = CalculateTownDistancesAndGetMin(townArray, townDistances, n, customerCoordinates);

	PrintClosestTownInfos(townArray, townDistances, n, minDistance);
}

bool IsReadTownInfosSuccessful(Town array[TOWN_ARRAY_SIZE], const int len)
{
	for (int i = 0; i < len; i++)
	{
		if (scanf("%d %d %s", &array[i].coordinates.x, &array[i].coordinates.y, array[i].name) != 3)
		{
			return false;
		}
	}

	return true;
}

int CalculateTownDistancesAndGetMin(const Town towns[TOWN_ARRAY_SIZE], int townDistances[TOWN_ARRAY_SIZE], const int len, const Coordinates coordinates)
{
	int minDistance = 0;

	for (int i = 0; i < len; i++)
	{
		townDistances[i] = abs(towns[i].coordinates.x - coordinates.x) + abs(towns[i].coordinates.y - coordinates.y);

		if (townDistances[i] < minDistance || i == 0)
		{
			minDistance = townDistances[i];
		}
	}

	return minDistance;
}

void PrintClosestTownInfos(const Town towns[TOWN_ARRAY_SIZE], const int townDistances[TOWN_ARRAY_SIZE], const int len, const int minDistance)
{
	for (int i = 0; i < len; i++)
	{
		if (townDistances[i] == minDistance)
		{
			printf("%s (%d, %d) distance = %d\n", towns[i].name, towns[i].coordinates.x, towns[i].coordinates.y, townDistances[i]);
		}
	}
}