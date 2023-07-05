#include "main.h"

/**
 * print_c - prints a char as string
 * @list: character to be printed as string
 * Return: String verion of characters
 */

char *print_c(va_list list)
{
	char *s;
	char d;

	d = va_arg(list, int);

	if (d == 0)
		d = '\0';

	s = malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = d;
	s[1] = '\0';

	return (s);
}
