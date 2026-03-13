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
bool IsSelfIntersect(Polygon polygon);
int GetSumOfArea(Polygon polygon);
void FreePointArray(Point** array, int len);

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

	if (IsSelfIntersect(polygon))
	{
		printf("Self-intersecting\n");
	}
	else if (IsPolygonConvex(polygon))
	{
		printf("Convex\n");

		const int areaSum = GetSumOfArea(polygon);
		printf("Area: %d.%d\n", areaSum / 2, areaSum % 2 * 5);
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

int Orient(const Point* P, const Point* Q, const Point* R)
{
	return (Q->x - P->x) * (R->y - P->y) - (Q->y - P->y) * (R->x - P->x);
}

int Min(const int a, const int b)
{
	if (a <= b)
		return a;

	return b;
}

int Max(const int a, const int b)
{
	if (a >= b)
		return a;

	return b;
}

bool isPointInsideASegment(const Point* A, const Point* B, const Point* C, const int orientCtoAB)
{
	return orientCtoAB == 0
		&& Min(A->x, B->x) <= C->x && C->x <= Max(A->x, B->x)
		&& Min(A->y, B->y) <= C->y && C->y <= Max(A->y, B->y);
}

bool IsSelfIntersect(Polygon polygon)
{
	const int lastMainSideIndex = polygon.verticesCount / 2 + polygon.verticesCount % 2;

	for (int i = 0; i < lastMainSideIndex; i++)
	{
		const Point* A = polygon.vertices[i];
		const Point* B = polygon.vertices[i + 1];

		int preventFallthroughRightSide = 0;
		if (i == 0)
			preventFallthroughRightSide = 1;

		for (int j = i + 2; j < polygon.verticesCount - preventFallthroughRightSide; j++)
		{
			const Point* C = polygon.vertices[j];
			const Point* D = polygon.vertices[(j + 1) % polygon.verticesCount];

			const int orientCtoAB = Orient(A, B, C);
			const int orientDtoAB = Orient(A, B, D);
			const int orientAtoCD = Orient(C, D, A);
			const int orientBtoCD = Orient(C, D, B);

			if (orientCtoAB * orientDtoAB < 0 && orientBtoCD * orientAtoCD < 0)
			{
				return true;
			}

			if (isPointInsideASegment(A, B, C, orientCtoAB) || isPointInsideASegment(A, B, D, orientDtoAB)
				|| isPointInsideASegment(C, D, A, orientAtoCD) || isPointInsideASegment(C, D, B, orientBtoCD))
			{
				return true;
			}
		}
	}

	return false;
}

int GetSumOfArea(const Polygon polygon)
{
	int sum = 0;

	for (int i = 0; i < polygon.verticesCount; i++)
	{
		const int j = (i + 1) % polygon.verticesCount;

		const Point* A = polygon.vertices[i];
		const Point* B = polygon.vertices[j];

		sum += A->x * B->y - A->y * B->x;
	}

	return sum;
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
	int cross = 0;

	for (int i = 0; i < polygon.verticesCount; i++)
	{
		const Point* A = polygon.vertices[i];
		const Point* B = polygon.vertices[(i + 1) % polygon.verticesCount];
		const Point* C = polygon.vertices[(i + 2) % polygon.verticesCount];

		const int currentCross = Orient(A, B, C);

		if (currentCross != 0)
		{
			if (cross == 0)
			{
				cross = currentCross;
			}
			else
			{
				if (cross * currentCross < 0)
					return false;
			}
		}
	}

	return true;
}