//
// Created by x3r1x on 27.03.2026.
//

#include <stdio.h>
int main()
{
	int a, b;

	if (fscanf(stdin, "%d %d", &a, &b) != 2)
	{
		fprintf(stderr, "Error!\n");
		return 1;
	}

	fprintf(stdout, "Sum = %d", a + b);
}