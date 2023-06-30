#include "main.h"

/**
 * _strcpy - Copies information
 * @dest: destination file containing copied info
 * @src: source file to be copied
 * Return: array of copied strings
 */

char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; x != '\0'; x++)
	{
		dest[x] = src[x];
	}

	dest[x] = src[x];
	return (dest);
}
