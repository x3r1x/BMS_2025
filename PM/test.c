//
// Created by x3r1x on 04.04.2026.
//

#include <stdint.h>
#include <stdio.h>

uint32_t LEToU32(const uint8_t in[4])
{
	return (uint8_t)in[0]
		| (uint8_t)in[1] << 8
		| (uint8_t)in[2] << 2 * 8
		| (uint8_t)in[3] << 3 * 8;
}

int main()
{
	uint8_t a[4];
	a[0] = 0x01;
	a[1] = 0x02;
	a[2] = 0x03;
	a[3] = 0x04;

	uint32_t digit = LEToU32(a);
	printf("%x", digit);
}