//
// Created by x3r1x on 12.03.2026.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} Point;

typedef struct
{
	Point** vertices;
	int verticesCount;
} Polygon;

bool IsPointInputSuccess(Point** array, int len, bool* isMemoryError);
bool IsPolygonConvex(Polygon polygon);
void FreePointArray(Point** array, int len);
void PrintPoints(Point** vertices, int len);

int main(void)
{
	Polygon polygon;
	bool isOutOfMemory;

	if (scanf("%d", &polygon.verticesCount) != 1 || polygon.verticesCount < 3)
		goto inputError;

	polygon.vertices = malloc(polygon.verticesCount * sizeof(Point*));
	if (polygon.vertices == nullptr)
		goto memoryError;

	if (!IsPointInputSuccess(polygon.vertices, polygon.verticesCount, &isOutOfMemory))
	{
		FreePointArray(polygon.vertices, polygon.verticesCount);
		goto inputError;
	}

	if (isOutOfMemory)
		goto memoryError;

	if (IsPolygonConvex(polygon))
	{
		printf("Convex\n");
	}
	else
	{
		printf("Not convex\n");
	}

	FreePointArray(polygon.vertices, polygon.verticesCount);
	return 0;

inputError:
	printf("Error: unexpected input\n");
	return 1;
memoryError:
	printf("Error: not enough memory!\n");

	FreePointArray(polygon.vertices, polygon.verticesCount);
	return 2;
}

void FreePointArray(Point** array, const int len)
{
	for (int i = 0; i < len; i++)
	{
		if (array[i] == nullptr)
			break;

		free(array[i]);
	}

	free(array);
}

bool IsPointInputSuccess(Point** array, const int len, bool* isMemoryError)
{
	*isMemoryError = false;

	for (int i = 0; i < len; i++)
	{
		Point* point = malloc(sizeof(Point));

		if (point == nullptr)
		{
			*isMemoryError = true;
			array[i] = nullptr;
			return false;
		}

		if (scanf("%d %d", &point->x, &point->y) != 2)
		{
			free(point);
			array[i] = nullptr;
			return false;
		}

		array[i] = point;
	}

	return true;
}

bool IsPolygonConvex(const Polygon polygon)
{
	bool isConvex = true;
	int cross = 0;

	for (int i = 0; i < polygon.verticesCount; i++)
	{
		const Point* A = polygon.vertices[i];
		const Point* B = polygon.vertices[(i + 1) % polygon.verticesCount];
		const Point* C = polygon.vertices[(i + 2) % polygon.verticesCount];

		const int currentCross = (B->x - A->x) * (C->y - B->y) - (B->y - A->y) * (C->x - B->x);

		if (currentCross != 0)
		{
			if (cross == 0)
			{
				cross = currentCross;
			}
			else
			{
				isConvex = cross * currentCross > 0;

				if (!isConvex)
					break;
			}
		}
	}

	return isConvex;
}

void PrintPoints(Point** vertices, const int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("Point %d: (%d; %d)\n", i + 1, vertices[i]->x, vertices[i]->y);
	}
}