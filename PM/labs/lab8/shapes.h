//
// Created by x3r1x on 20.04.2026.
//

#ifndef SHAPES_H
#define SHAPES_H

#include <stdint.h>

typedef struct Shape Shape;

typedef struct
{
	double x;
	double y;
} Point;

typedef struct
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} Color;

Shape* CreateCircle(Point center, double radius, Color color);
Shape* CreateRectangle(Point topLeft, double width, double height, Color color);
Shape* CreateTriangle(Point point1, Point point2, Point point3, Color color);

double GetShapeArea(const Shape* shape);
double GetShapePerimeter(const Shape* shape);

void PrintShapeInfo(const Shape* shape);
void DestroyShape(Shape* shape);

#endif // SHAPES_H
