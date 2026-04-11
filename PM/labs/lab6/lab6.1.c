//
// Created by x3r1x on 11.04.2026.
//

#include <stdint.h>
#include <stdio.h>
#include <string.h>

constexpr int MAX_MANTISSA = 0x7FFFFF;
constexpr int MAX_EXPONENT = 255;

typedef enum
{
	OK_STATUS = 0,
	MANTISSA_ERROR_STATUS = 1
} Statuses;

int BuildFloat(bool sign, uint8_t exponent, uint32_t mantissa, float* result);
void FloatResearch();
bool IsFloatInputSuccessful();

int main()
{
	FloatResearch();

	if (!IsFloatInputSuccessful())
	{
		printf("Error!");
		return 1;
	}
}

int BuildFloat(const bool sign, const uint8_t exponent, const uint32_t mantissa, float* result)
{
	uint32_t number = 0;

	number = sign << 31;
	number |= exponent << 23;

	if (mantissa > MAX_MANTISSA)
	{
		return MANTISSA_ERROR_STATUS;
	}

	number |= mantissa;

	memcpy((uint8_t*) result, (uint8_t*) &number, sizeof(float));

	return OK_STATUS;
}

bool IsFloatInputSuccessful()
{
	int sign, exponent, mantissa;
	float num;

	scanf("%d %d %i", &sign, &exponent, &mantissa);

	if ((sign != 1 && sign != 0) || exponent < 0 || exponent > MAX_EXPONENT || mantissa > MAX_MANTISSA || mantissa < 0)
	{
		return false;
	}

	if (BuildFloat(sign, exponent, (uint32_t) mantissa, &num) != OK_STATUS)
	{
		return false;
	}

	printf("%f", num);

	return true;
}

void FloatResearch()
{
	float result;

	BuildFloat(0, MAX_EXPONENT, 0, &result);
	printf("%f\n", result);

	BuildFloat(1, MAX_EXPONENT, 0, &result);
	printf("%f\n", result);

	BuildFloat(1, MAX_EXPONENT, 1, &result);
	printf("%f\n", result);

	BuildFloat(1, 127, 0, &result);
	printf("%f\n", result);

	BuildFloat(0, 129, 0x200000, &result);
	printf("%f\n", result);

	BuildFloat(1, 125, 0, &result);
	printf("%f\n", result);

	BuildFloat(0, 0, 0, &result);
	printf("%f\n", result);
}