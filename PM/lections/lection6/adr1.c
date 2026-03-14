//
// Created by x3r1x on 14.03.2026.
//

#include <stdio.h>

int main()
{
	int arr[5] = {10, 20, 30, 40, 50};

	int* p = arr;

	int* p1 = &arr[4];
	int* p2 = &arr[1];

	printf("p        = %p\n", p);
	printf("p + 2    = %p\n", p + 2);
	printf("*(p + 2) = %d\n", *(p + 2));

	printf("p1 - p2  = %ld\n", p1 - p2);
	printf("p1 - 2   = %p\n", (void*)(p1 - 2));
}