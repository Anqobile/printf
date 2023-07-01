#include "main.h"

/**
 * itoOctal - change integer to octal
 * @list: int to be changed
 * Return: octal string
 */

char *itoOctal(va_list list)
{
	int m = 0, eights = 1;
	int n, k;
	char *s;

	k = va_arg(list, int);
	n = k;

	s = malloc(sizeof(char) * 12);
	if (s == NULL)
		return (NULL);

	if (k < 0)
	{
		s[0] = 1 + '0';
		m++;
		k *= -1;
		n *= -1;
	}

	/* find largest power of 8 it's divisible by */
	while (k > 1)
	{
		k /= 8;
		eights *= 8;
	}

	while (eights > 0)
	{
		s[m++] = (n / eights + '0');
		n %= eights;
		eights /= 8;
	}
	s[m] = '\0';

	return (s);
}
