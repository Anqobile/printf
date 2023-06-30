#include "main.h"

/**
 * itob - converts int to binary
 * @list: int to change to binary
 * Return: string with binary
 */

char *itob(va_list list)
{
	int m = 0, toos = 1;
	int i, q;
	char *s;

	q = va_arg(list, int);
	i = q;

	s = malloc(sizeof(char) * 33);
	if (s == NULL)
		return (NULL);

	if (q < 0)
	{
		s[0] = 1 + '0';
		m++;
		q *= -1;
		i *= -1;
	}

	while (q > 1)
	{
		q /= 2;
		toos *= 2;
	}

	while (toos > 0)
	{
		s[m++] = (i / toos + '0');
		i %= toos;
		toos /= 2;
	}
	s[m] = '\0';

	return (s);
}
