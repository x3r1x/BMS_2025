//
// Created by x3r1x on 04.04.2026.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int MAX_BIT_SHIFT = 8;

char* ReadString();
void Encrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key);
void Decrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key);
void PrintDump(const uint8_t* data, size_t size);

int main(void)
{
	uint8_t key;
	char* originalText = ReadString();
	const size_t len = strlen(originalText) + 1;

	uint8_t* encryptedText = malloc(len);
	uint8_t* decryptedText = malloc(len);

	if (encryptedText == nullptr || decryptedText == nullptr) goto error;

	if (originalText == nullptr || scanf("%hhu", &key) != 1)
		goto error;

	Encrypt((uint8_t*)originalText, encryptedText, len, key);

	if (encryptedText == nullptr)
		goto error;

	Decrypt(encryptedText, decryptedText, len, key);

	if (decryptedText == nullptr) goto error;

	printf("Dump of original string: ");
	PrintDump(decryptedText, len);

	printf("Dump of encrypted string: ");
	PrintDump(encryptedText, len);

	printf("Dump of decrypted string: ");
	PrintDump(decryptedText, len);

	free(encryptedText);
	free(decryptedText);
	free(originalText);
	return 0;

error:
	free(originalText);
	free(encryptedText);
	free(decryptedText);
	printf("Error!");
	return 1;
}

char* ReadString()
{
	char* str = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		char* newStrPtr = realloc(str, len + 1);

		if (newStrPtr == nullptr)
		{
			goto error;
		}

		str = newStrPtr;
		str[len++] = (char)ch;
	}

	char* newStrPtr = realloc(str, len + 1);

	if (newStrPtr == nullptr)
	{
		goto error;
	}

	str = newStrPtr;
	str[len] = '\0';
	return str;

error:
	free(str);
	return nullptr;
}

void PrintDump(const uint8_t* data, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%02X ", data[i]);
	}

	printf("\n");
}

uint8_t RotateRight(const uint8_t value, unsigned int n)
{
	n %= MAX_BIT_SHIFT;

	return value >> n | value << (MAX_BIT_SHIFT - n);
}

uint8_t RotateLeft(const uint8_t value, unsigned int n)
{
	n %= MAX_BIT_SHIFT;

	return value << n | value >> (MAX_BIT_SHIFT - n);
}

void Encrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key)
{
	for (int i = 0; i < size; i++)
	{
		dst[i] = RotateRight(src[i], i);
		dst[i] = dst[i] ^ key;
	}
}

void Decrypt(const uint8_t* src, uint8_t* dst, size_t size, uint8_t key)
{
	for (int i = 0; i < size; i++)
	{
		dst[i] = src[i] ^ key;
		dst[i] = RotateLeft(dst[i], i);
	}
}