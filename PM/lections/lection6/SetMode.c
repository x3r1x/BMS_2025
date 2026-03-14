//
// Created by x3r1x on 14.03.2026.
//

#include <stdio.h>
typedef struct
{
	unsigned char ready: 1;
	unsigned char error: 1;
	unsigned char mode : 2;
	unsigned char state: 3;
} Status;

int main()
{
	Status s = {0};

	s.mode = 3;

	printf("sizeof(States) = %zu\n", sizeof(Status));
	printf("mode = %u\n", s.mode);
}