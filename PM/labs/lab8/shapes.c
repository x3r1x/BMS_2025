//
// Created by x3r1x on 20.04.2026.
//

#include "shapes.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function pointers, Shape type & Virtual Table

typedef double (*GetShapeAreaFunc)(const Shape* self);
typedef double (*GetShapePerimeterFunc)(const Shape* self);

typedef void (*PrintShapeInfoFunc)(const Shape* self);
typedef void (*DestroyShapeFunc)(Shape* self);

typedef struct
{
	GetShapeAreaFunc getArea;
	GetShapePerimeterFunc getPerimeter;
	PrintShapeInfoFunc info;
} ShapeVTbl;

struct Shape
{
	const ShapeVTbl* vTbl;
	Color color;
};

// Interface functions

double GetShapeArea(const Shape* shape)
{
	return shape->vTbl->getArea(shape);
}

double GetShapePerimeter(const Shape* shape)
{
	return shape->vTbl->getPerimeter(shape);
}

void PrintShapeInfo(const Shape* shape)
{
	shape->vTbl->info(shape);
}

void DestroyShape(Shape* shape)
{
	free(shape);
}

// Circle realization

typedef struct
{
	Shape base;
	Point center;
	double radius;
} Circle;

static double GetCircleArea(const Shape* self)
{
	const Circle* circle = (const Circle*)self;

	return M_PI * pow(circle->radius, 2);
}

static double GetCirclePerimeter(const Shape* self)
{
	const Circle* circle = (const Circle*)self;

	return 2 * M_PI * circle->radius;
}

static void PrintCircleInfo(const Shape* self)
{
	const Circle* circle = (const Circle*)self;

	printf("circle x=%lf y=%lf radius=%lf color=#%.02X%.02X%.02X area=%lf perimeter=%lf\n", circle->center.x, circle->center.y,
		circle->radius, circle->base.color.r, circle->base.color.g, circle->base.color.b,
		circle->base.vTbl->getArea(self), circle->base.vTbl->getPerimeter(self));
}

static const ShapeVTbl circleVTbl = {
	.getArea = GetCircleArea,
	.getPerimeter = GetCirclePerimeter,
	.info = PrintCircleInfo
};

Shape* CreateCircle(const Point center, const double radius, const Color color)
{
	Circle* circle = malloc(sizeof(Circle));

	if (circle != nullptr)
	{
		circle->base.vTbl = &circleVTbl;
		circle->base.color = color,
		circle->center = center;
		circle->radius = radius;
	}

	return (Shape*)circle;
}

// Rectangle realization

typedef struct
{
	Shape base;
	Point topLeft;
	double width;
	double height;
} Rectangle;

static double GetRectangleArea(const Shape* self)
{
	const Rectangle* rectangle = (const Rectangle*)self;

	return rectangle->height * rectangle->width;
}

static double GetRectanglePerimeter(const Shape* self)
{
	const Rectangle* rectangle = (const Rectangle*)self;

	return (rectangle->width + rectangle->height) * 2;
}

static void PrintRectangleInfo(const Shape* self)
{
	const Rectangle* rectangle = (const Rectangle*)self;

	printf("rectangle left=%lf top=%lf width=%lf height=%lf color=#%.02X%.02X%.02X area=%lf perimeter=%lf\n", rectangle->topLeft.x,
		rectangle->topLeft.y, rectangle->width, rectangle->height, rectangle->base.color.r, rectangle->base.color.g, rectangle->base.color.b,
		rectangle->base.vTbl->getArea(self), rectangle->base.vTbl->getPerimeter(self));
}

static const ShapeVTbl rectangleVTbl = {
	.getArea = GetRectangleArea,
	.getPerimeter = GetRectanglePerimeter,
	.info = PrintRectangleInfo
};

Shape* CreateRectangle(Point topLeft, double width, double height, Color color)
{
	Rectangle* rectangle = malloc(sizeof(Rectangle));

	if (rectangle != nullptr)
	{
		rectangle->base.vTbl = &rectangleVTbl;
		rectangle->base.color = color;
		rectangle->topLeft = topLeft;
		rectangle->width = width;
		rectangle->height = height;
	}

	return (Shape*)rectangle;
}

// Triangle realization

typedef struct
{
	Shape base;
	Point point1;
	Point point2;
	Point point3;
} Triangle;

static double GetTriangleArea(const Shape* self)
{
	const Triangle* triangle = (const Triangle*)self;

	return 0.5 * fabs(triangle->point1.x * (triangle->point2.y - triangle->point3.y) + triangle->point2.x * (triangle->point3.y - triangle->point1.y) + triangle->point3.x * (triangle->point1.y - triangle->point2.y));
}

static double GetTrianglePerimeter(const Shape* self)
{
	const Triangle* triangle = (const Triangle*)self;

	const double side1 = sqrt(pow(triangle->point2.x - triangle->point1.x, 2) + pow(triangle->point2.y - triangle->point1.y, 2));
	const double side2 = sqrt(pow(triangle->point3.x - triangle->point2.x, 2) + pow(triangle->point3.y - triangle->point2.y, 2));
	const double side3 = sqrt(pow(triangle->point1.x - triangle->point3.x, 2) + pow(triangle->point1.y - triangle->point3.y, 2));

	return side1 + side2 + side3;
}

static void PrintTriangleInfo(const Shape* self)
{
	const Triangle* triangle = (const Triangle*)self;

	printf("triangle x1=%lf y1=%lf x2=%lf y2=%lf x3=%lf y3=%lf color=#%.02X%.02X%.02X area=%lf perimeter=%lf\n", triangle->point1.x,
		triangle->point1.y, triangle->point2.x, triangle->point2.y, triangle->point3.x, triangle->point3.y, triangle->base.color.r, triangle->base.color.g,
		triangle->base.color.b, triangle->base.vTbl->getArea(self), triangle->base.vTbl->getPerimeter(self));
}

static const ShapeVTbl triangleVTbl = {
	.getArea = GetTriangleArea,
	.getPerimeter = GetTrianglePerimeter,
	.info = PrintTriangleInfo
};

Shape* CreateTriangle(const Point point1, const Point point2, const Point point3, const Color color)
{
	Triangle* triangle = malloc(sizeof(Triangle));

	if (triangle != nullptr)
	{
		triangle->base.vTbl = &triangleVTbl;
		triangle->base.color = color;
		triangle->point1 = point1;
		triangle->point2 = point2;
		triangle->point3 = point3;
	}

	return (Shape*)triangle;
}