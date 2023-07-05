#include "main.h"

/**
 * get_size - Calculates the buffer size to cast the argument
 * @format: Formatted string to print the arguments
 * @i: List of args to be printed.
 * Return: buffer size.
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int siz = 0;

	if (format[curr_i] == 'l')
		siz = S_LONG;
	else if (format[curr_i] == 'h')
		siz = S_SHORT;

	if (siz == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (siz);
}
