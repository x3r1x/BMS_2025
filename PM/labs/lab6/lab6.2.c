//
// Created by x3r1x on 11.04.2026.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

constexpr int NO_INTERSECTION = -1;
constexpr double EPSILON = 1e-6;

typedef struct
{
	double x;
	double y;
} Point;

typedef struct
{
	double x;
	double y;
} Vector;

typedef struct
{
	Point coordinates;
	double radius;
} Island;

typedef struct
{
	double A;
	double B;
	double C;
} SquareEquationCoefficients;

typedef struct
{
	int index;
	double timeToReach;
	Point coordinates;
	bool isRepetitive;
} IntersectionInfo;

bool IsInputReadSuccessful(Point* startDot, Vector* direction, int* islandsCount);
bool IsInsideAnIsland(Point startPos, Island* islands, int islandsCount);
Island* ReadIslandsArray(int islandsCount);
IntersectionInfo GetIntersectionInfo(Point startPos, Vector direction, const Island* islands, int islandsCount);
void WriteIntersectionInfo(IntersectionInfo info);

int main()
{
	Point startDot;
	Vector direction;
	Island* islands;
	int islandsCount;

	if (!IsInputReadSuccessful(&startDot, &direction, &islandsCount))
	{
		printf("Error: wrong input!\n");
		return 1;
	}

	islands = ReadIslandsArray(islandsCount);

	if (islands == nullptr)
	{
		printf("Error!\n");
		return 1;
	}

	if (IsInsideAnIsland(startDot, islands, islandsCount))
	{
		printf("You are inside an island!");
		free(islands);
		return 0;
	}

	WriteIntersectionInfo(GetIntersectionInfo(startDot, direction, islands, islandsCount));

	free(islands);
}

bool IsInputReadSuccessful(Point* startDot, Vector* direction, int* islandsCount)
{
	if (scanf("%lf %lf", &startDot->x, &startDot->y) != 2)
	{
		return false;
	}

	if (scanf("%lf %lf", &direction->x, &direction->y) != 2)
	{
		return false;
	}

	if (scanf("%d", islandsCount) != 1)
	{
		return false;
	}

	return true;
}

Island* ReadIslandsArray(const int islandsCount)
{
	Island* islandsArray = malloc(islandsCount * sizeof(Island));

	if (islandsArray == nullptr)
	{
		return nullptr;
	}

	for (int i = 0; i < islandsCount; i++)
	{
		if (scanf("%lf %lf %lf", &islandsArray[i].coordinates.x, &islandsArray[i].coordinates.y, &islandsArray[i].radius) != 3)
		{
			free(islandsArray);
			return nullptr;
		}
	}

	return islandsArray;
}

SquareEquationCoefficients GetCoefficients(const Point startDot, const Vector direction, const Island island, const double coefficientA)
{
	SquareEquationCoefficients coefficients;

	coefficients.A = coefficientA;
	coefficients.B = 2 * (direction.x * (startDot.x - island.coordinates.x) + direction.y * (startDot.y - island.coordinates.y));
	coefficients.C = pow(startDot.x - island.coordinates.x, 2) + pow(startDot.y - island.coordinates.y, 2) - pow(island.radius, 2);

	return coefficients;
}

double GetDiscriminant(const SquareEquationCoefficients coefficients)
{
	return pow(coefficients.B, 2) - 4 * coefficients.C * coefficients.A;
}

double GetMinTime(const SquareEquationCoefficients coefficients, const double discriminant)
{
	return (-coefficients.B - sqrt(discriminant)) / (2 * coefficients.A);
}

void CalculateIntersectionCoordinates(const Point startPos, const Vector direction, IntersectionInfo* closestIslandInfo)
{
	Point intersectionCoordinates;

	intersectionCoordinates.x = startPos.x + direction.x * closestIslandInfo->timeToReach;
	intersectionCoordinates.y = startPos.y + direction.y * closestIslandInfo->timeToReach;

	closestIslandInfo->coordinates = intersectionCoordinates;
}

IntersectionInfo GetIntersectionInfo(const Point startPos, const Vector direction, const Island* islands, const int islandsCount)
{
	IntersectionInfo closestIslandInfo = {
		.index = NO_INTERSECTION,
		.coordinates = 0,
		.timeToReach = 0,
		.isRepetitive = 0
	};

	double coefficientA = pow(direction.x, 2) + pow(direction.y, 2);

	for (int i = 0; i < islandsCount; i++)
	{
		const SquareEquationCoefficients coefficients = GetCoefficients(startPos, direction, islands[i], coefficientA);
		const double discriminant = GetDiscriminant(coefficients);

		if (discriminant >= 0)
		{
			const double timeToReachCurrentIsland = GetMinTime(coefficients, discriminant);

			if (timeToReachCurrentIsland >= 0 && (timeToReachCurrentIsland - closestIslandInfo.timeToReach < EPSILON || closestIslandInfo.index == NO_INTERSECTION))
			{
				if (timeToReachCurrentIsland == closestIslandInfo.timeToReach)
				{
					closestIslandInfo.isRepetitive = true;
				}
				else
				{
					closestIslandInfo.index = i;
					closestIslandInfo.timeToReach = timeToReachCurrentIsland;
				}
			}
		}
	}

	CalculateIntersectionCoordinates(startPos, direction, &closestIslandInfo);
	return closestIslandInfo;
}

void WriteIntersectionInfo(const IntersectionInfo info)
{
	if (info.index == NO_INTERSECTION)
	{
		printf("No intersection found!");
		return;
	}

	printf("Time to reach island: %lf\nCoordinates: (%lf, %lf)\n", info.timeToReach, info.coordinates.x, info.coordinates.y);

	if (info.isRepetitive)
	{
		printf("There are two islands in here!\n");
	}
}

bool IsInsideAnIsland(Point startPos, Island* islands, int islandsCount)
{
	for (int i = 0; i < islandsCount; i++)
	{
		if (pow(islands[i].coordinates.x - startPos.x, 2) + pow(islands[i].coordinates.y - startPos.y, 2) <= pow(islands[i].radius, 2))
		{
			return true;
		}
	}

	return false;
}