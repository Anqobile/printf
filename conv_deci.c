#include "main.h"

/**
 * _itos - convert an integer to a string
 * @div: multiple of 10
 * @length: number length
 * @n: digits to convert to string
 * Return: string (made from int)
 **/

char *_itos(int div, int length, int n)
{
	char *str;
	int u = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
		return (NULL);

	if (u < 0) /* accounts for neg sign */
	{
		str[0] = '-';
		u++;
	}
	while (n < 0)
	{
		str[u] = ((n / div) * -1 + '0');
		n = n % div;
		div /= 10;
		u++;
	}
	while (div >= 1)
	{
		str[u] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		u++;
	}
	str[u] = '\0';
	return (str);
}

/**
 * print_d - gets length to put in int-to-str function
 * @list: takes arguments
 * Return: integer string
 **/

char *print_d(va_list list)
{
	int length, divid, m, temp;

	m = va_arg(list, int);
	temp = m;
	length = 0;
	divid = 1;

	if (m == 0)
	{
		length++;
		return (_itos(divid, length, m));
	}

	while (temp != 0)
	{
		length += 1;
		if (length > 1)
			divid *= 10;
		temp /= 10;
	}

	return (_itos(divid, length, m));
}
