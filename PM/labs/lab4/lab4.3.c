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
	Point* vertices;
	int verticesCount;
} Polygon;

bool IsPointInputSuccess(Point* array, int len, bool* isMemoryError);
bool IsPolygonConvex(Polygon polygon);
bool IsSelfIntersect(Polygon polygon);
int GetSumOfArea(Polygon polygon);

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
		free(polygon.vertices);
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

	free(polygon.vertices);
	return 0;

inputError:
	printf("Error: unexpected input\n");
	return 1;
memoryError:
	printf("Error: not enough memory!\n");

	free(polygon.vertices);
	return 2;
}

int Orient(const Point p, const Point q, const Point r)
{
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
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

bool isPointInsideASegment(const Point a, const Point b, const Point c, const int orientCtoAB)
{
	return orientCtoAB == 0
		&& Min(a.x, b.x) <= c.x && c.x <= Max(a.x, b.x)
		&& Min(a.y, b.y) <= c.y && c.y <= Max(a.y, b.y);
}

bool AreSidesIntersectingWithMainSide(const Point a, const Point b, const Polygon polygon, const int index)
{
	int preventFallThroughRightSide = 0;
	if (index == 0)
		preventFallThroughRightSide = 1;

	for (int j = index + 2; j < polygon.verticesCount - preventFallThroughRightSide; j++)
	{
		const Point c = polygon.vertices[j];
		const Point d = polygon.vertices[(j + 1) % polygon.verticesCount];

		const int orientCtoAB = Orient(a, b, c);
		const int orientDtoAB = Orient(a, b, d);
		const int orientAtoCD = Orient(c, d, a);
		const int orientBtoCD = Orient(c, d, b);

		if (orientCtoAB * orientDtoAB < 0 && orientBtoCD * orientAtoCD < 0)
		{
			return true;
		}

		if (isPointInsideASegment(a, b, c, orientCtoAB) || isPointInsideASegment(a, b, d, orientDtoAB)
			|| isPointInsideASegment(c, d, a, orientAtoCD) || isPointInsideASegment(c, d, b, orientBtoCD))
		{
			return true;
		}
	}

	return false;
}

bool IsSelfIntersect(const Polygon polygon)
{
	const int lastMainSideIndex = polygon.verticesCount / 2 + polygon.verticesCount % 2;

	for (int i = 0; i < lastMainSideIndex; i++)
	{
		const Point a = polygon.vertices[i];
		const Point b = polygon.vertices[i + 1];

		if (AreSidesIntersectingWithMainSide(a, b, polygon, i))
		{
			return true;
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

		const Point a = polygon.vertices[i];
		const Point b = polygon.vertices[j];

		sum += a.x * b.y - a.y * b.x;
	}

	return sum;
}

bool IsPointInputSuccess(Point* array, const int len, bool* isMemoryError)
{
	*isMemoryError = false;

	for (int i = 0; i < len; i++)
	{
		if (scanf("%d %d", &array[i].x, &array[i].y) != 2)
		{
			return false;
		}
	}

	return true;
}

bool IsPolygonConvex(const Polygon polygon)
{
	int cross = 0;

	for (int i = 0; i < polygon.verticesCount; i++)
	{
		const Point a = polygon.vertices[i];
		const Point b = polygon.vertices[(i + 1) % polygon.verticesCount];
		const Point c = polygon.vertices[(i + 2) % polygon.verticesCount];

		const int currentCross = Orient(a, b, c);

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