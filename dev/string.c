#include "main.h"

/**
 * print_s - takes string and return string
 * @list: list of strings
 * Return: string
 */

char *print_s(va_list list)
{
	char *s;
	char *q;
	int len;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	len = _strlen(s);

	q = malloc(sizeof(char) * len + 1);
	if (q == NULL)
		return (NULL);

	return (_strcpy(q, s));
}
