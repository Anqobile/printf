#include "main.h"

/**
 * _strlen - outputs length of a string as an integer
 * @s: string passed to function (to get length of)
 * Return: b (the length of string)
 */

int _strlen(char *s)
{
	int b = 0;

	while (*(s + b))
		b++;

	return (b);
}
