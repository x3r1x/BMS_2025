//
// Created by x3r1x on 14.03.2026.
//

#include <stdio.h>

typedef union
{
	struct
	{
		int x;
		int y;
	};

	int v[2];
} Point;

int main()
{
	Point p = {.x = 10, .y = 20};
	printf("x    = %d, y    = %d\n", p.x, p.y);
	printf("v[0] = %d, v[1] = %d\n", p.v[0], p.v[1]);

	p.v[0] = 30;
	p.v[1] = 40;
	printf("x    = %d, y    = %d\n", p.x, p.y);
}