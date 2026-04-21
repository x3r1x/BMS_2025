//
// Created by x3r1x on 21.04.2026.
//

#include "shapes.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int MAX_BUFFER_SIZE = 11;
constexpr char CIRCLE_STRING[7] = "circle";
constexpr char RECTANGLE_STRING[10] = "rectangle";
constexpr char TRIANGLE_STRING[9] = "triangle";

typedef enum
{
	CIRCLE,
	RECTANGLE,
	TRIANGLE
} ShapeTypes;

typedef struct
{
	Shape* shape;
	ShapeTypes type;
	double area;
	double perimeter;
} ShapeInfo;

typedef struct
{
	Point center;
	double radius;
	Color color;
} CircleParamsType;

typedef struct
{
	Point topLeft;
	double width;
	double height;
	Color color;
} RectangleParamsType;

typedef struct
{
	Point point1;
	Point point2;
	Point point3;
	Color color;
} TriangleParamsType;

void DestroyShapeInfoArray(ShapeInfo* array, const int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i].shape != nullptr)
		{
			free(array[i].shape);
		}
	}

	free(array);
}

bool IsReadingTypeSuccessful(ShapeInfo* shape, char buffer[MAX_BUFFER_SIZE])
{
	if (strcmp(buffer, CIRCLE_STRING) == 0)
	{
		shape->type = CIRCLE;
	}
	else if (strcmp(buffer, RECTANGLE_STRING) == 0)
	{
		shape->type = RECTANGLE;
	}
	else if (strcmp(buffer, TRIANGLE_STRING) == 0)
	{
		shape->type = TRIANGLE;
	}
	else
	{

		return false;
	}

	return true;
}

bool IsCreatingCircleParamsSuccessful(ShapeInfo* shapeInfo)
{
	CircleParamsType params = { 0 };

	if (scanf("%lf %lf %lf #%2hhx%2hhx%2hhx", &params.center.x, &params.center.y, &params.radius,
			&params.color.r, &params.color.g, &params.color.b)
		!= 6)
	{
		return false;
	}

	if (params.radius < 0)
	{
		return false;
	}

	if ((shapeInfo->shape = CreateCircle(params.center, params.radius, params.color)) == nullptr)
	{
		return false;
	}

	return true;
}

bool IsCreatingRectangleParamsSuccessful(ShapeInfo* shapeInfo)
{
	RectangleParamsType params = { 0 };

	if (scanf("%lf %lf %lf %lf #%2hhx%2hhx%2hhx\n", &params.topLeft.x, &params.topLeft.y, &params.width, &params.height,
			&params.color.r, &params.color.g, &params.color.b)
		!= 7)
	{
		return false;
	}

	if (params.width < 0 || params.height < 0)
	{
		return false;
	}

	if ((shapeInfo->shape = CreateRectangle(params.topLeft, params.width, params.height, params.color)) == nullptr)
	{
		return false;
	}

	return true;
}

bool IsCreatingTriangleSuccessful(ShapeInfo* shapeInfo)
{
	TriangleParamsType params = { 0 };

	if (scanf("%lf %lf %lf %lf %lf %lf #%2hhx%2hhx%2hhx\n", &params.point1.x, &params.point1.y, &params.point2.x, &params.point2.y,
			&params.point3.x, &params.point3.y, &params.color.r, &params.color.g, &params.color.b)
		!= 9)
	{
		return false;
	}

	if ((shapeInfo->shape = CreateTriangle(params.point1, params.point2, params.point3, params.color)) == nullptr)
	{
		return false;
	}

	return true;
}

ShapeInfo* ReadShapeArray(const int arraySize)
{
	char buffer[MAX_BUFFER_SIZE];
	ShapeInfo* shapeArray = malloc(arraySize * sizeof(ShapeInfo));

	if (shapeArray == nullptr)
	{
		return nullptr;
	}

	for (int i = 0; i < arraySize; i++)
	{
		if (scanf("%s", buffer) != 1)
		{
			return nullptr;
		}

		if (!IsReadingTypeSuccessful(&shapeArray[i], buffer))
		{
			return nullptr;
		}

		switch (shapeArray[i].type)
		{
		case CIRCLE:
			if (!IsCreatingCircleParamsSuccessful(&shapeArray[i]))
			{
				return nullptr;
			}
			break;
		case RECTANGLE:
			if (!IsCreatingRectangleParamsSuccessful(&shapeArray[i]))
			{
				return nullptr;
			}
			break;
		case TRIANGLE:
			if (!IsCreatingTriangleSuccessful(&shapeArray[i]))
			{
				return nullptr;
			}
			break;
		}
	}

	return shapeArray;
}

void FindShapeIndicators(ShapeInfo** shapes, const int shapeAmount)
{
	for (int i = 0; i < shapeAmount; i++)
	{
		(*shapes)[i].area = GetShapeArea((*shapes)[i].shape);
		(*shapes)[i].perimeter = GetShapePerimeter((*shapes)[i].shape);
	}
}

int AreaAscendingComparator(const void* a, const void* b)
{
	const ShapeInfo shape1 = *(const ShapeInfo*)a;
	const ShapeInfo shape2 = *(const ShapeInfo*)b;

	return shape1.area < shape2.area ? -1 : shape1.area > shape2.area ? 1
																	  : 0;
}

int PerimeterDescendingComparator(const void* a, const void* b)
{
	const ShapeInfo shape1 = *(const ShapeInfo*)a;
	const ShapeInfo shape2 = *(const ShapeInfo*)b;

	return shape1.perimeter < shape2.perimeter ? 1 : shape1.perimeter > shape2.perimeter ? -1
																						 : 0;
}

void PrintShapeInfoArray(ShapeInfo** shapes, const int shapesAmount)
{
	for (int i = 0; i < shapesAmount; i++)
	{
		PrintShapeInfo((*shapes)[i].shape);
	}
}

void WriteResearchResult(ShapeInfo* shapes, const int shapesAmount)
{
	printf("Area ascending:\n\n");
	qsort(shapes, shapesAmount, sizeof(ShapeInfo), AreaAscendingComparator);
	PrintShapeInfoArray(&shapes, shapesAmount);

	printf("\nPerimeter descending:\n\n");
	qsort(shapes, shapesAmount, sizeof(ShapeInfo), PerimeterDescendingComparator);
	PrintShapeInfoArray(&shapes, shapesAmount);
}

int main()
{
	int N;
	ShapeInfo* shapes;

	if (scanf("%d", &N) != 1)
	{
		fprintf(stderr, "Error!\n");
		return 1;
	}

	if ((shapes = ReadShapeArray(N)) == nullptr)
	{
		DestroyShapeInfoArray(shapes, N);
		fprintf(stderr, "Error!\n");
		return 1;
	}

	FindShapeIndicators(&shapes, N);
	WriteResearchResult(shapes, N);

	DestroyShapeInfoArray(shapes, N);
}