//
// Created by x3r1x on 21.04.2026.
//

#include "shapes.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int MAX_SHAPE_STRING_SIZE = 11;
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
	ShapeInfo* array;
	int size;
} ShapeArray;

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

void DestroyShapeInfoArray(const ShapeArray* array)
{
	for (int i = 0; i < array->size; i++)
	{
		if (array->array[i].shape != nullptr)
		{
			free(array->array[i].shape);
		}
	}

	free(array->array);
}

bool IsReadingTypeSuccessful(ShapeInfo* shape, char buffer[MAX_SHAPE_STRING_SIZE])
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

bool ReadShapeArray(ShapeArray* array, const int arraySize)
{
	char buffer[MAX_SHAPE_STRING_SIZE];
	array->array = calloc(arraySize, sizeof(ShapeInfo));
	array->size = 0;

	if (array->array == nullptr)
	{
		return false;
	}

	for (int i = 0; i < arraySize; i++)
	{
		if (scanf("%s", buffer) != 1)
		{
			goto error;
		}

		if (!IsReadingTypeSuccessful(&array->array[i], buffer))
		{
			goto error;
		}

		switch (array->array[i].type)
		{
		case CIRCLE:
			if (!IsCreatingCircleParamsSuccessful(&array->array[i]))
			{
				goto error;
			}
			break;
		case RECTANGLE:
			if (!IsCreatingRectangleParamsSuccessful(&array->array[i]))
			{
				goto error;
			}
			break;
		case TRIANGLE:
			if (!IsCreatingTriangleSuccessful(&array->array[i]))
			{
				goto error;
			}
			break;
		}

		array->size++;
	}

	return true;
error:
	DestroyShapeInfoArray(array);
	return false;
}

void FindShapeIndicators(ShapeArray* array)
{
	for (int i = 0; i < array->size; i++)
	{
		array->array[i].area = GetShapeArea(array->array[i].shape);
		array->array[i].perimeter = GetShapePerimeter(array->array[i].shape);
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

void PrintShapeInfoArray(const ShapeArray* array)
{
	for (int i = 0; i < array->size; i++)
	{
		PrintShapeInfo(array->array[i].shape);
	}
}

void WriteResearchResult(ShapeArray array)
{
	printf("Area ascending:\n\n");
	qsort(array.array, array.size, sizeof(ShapeInfo), AreaAscendingComparator);
	PrintShapeInfoArray(&array);

	printf("\nPerimeter descending:\n\n");
	qsort(array.array, array.size, sizeof(ShapeInfo), PerimeterDescendingComparator);
	PrintShapeInfoArray(&array);
}

int main()
{
	int N;
	ShapeArray array = { 0 };

	if (scanf("%d", &N) != 1)
	{
		fprintf(stderr, "Error!\n");
		return 1;
	}

	if (!ReadShapeArray(&array, N))
	{
		fprintf(stderr, "Error!\n");
		return 1;
	}

	FindShapeIndicators(&array);
	WriteResearchResult(array);

	DestroyShapeInfoArray(&array);
}