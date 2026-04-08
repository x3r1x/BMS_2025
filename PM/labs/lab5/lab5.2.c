//
// Created by x3r1x on 04.04.2026.
//

#include <stdint.h>
#include <stdio.h>

void Encrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key);

int main(void)
{
	uint8_t key;
	char text[51];

	fgets(text, 50, stdin);
	if (scanf("%hhu", &key) != 1)
	{
		printf("Error: incorrect input!");
		return 1;
	}
}

void Encrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key)
{
	for (int i = 0; i < size; i++)
	{
		
	}
}