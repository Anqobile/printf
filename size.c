#include "main.h"

/**
 * get_size - Computes size to cast arguments
 * @format: Formatted string to print the arguments
 * @d: arguments list to be printed.
 * Return: Precision.
 */

int get_size(const char *format, int *d)
{
	int mur_d = *d + 1;
	int size = 0;

	if (format[mur_d] == 'l')
		size = S_LONG;
	else if (format[mur_d] == 'h')
		size = S_SHORT;
	if (size == 0)
		*d = mur_d - 1;
	else
		*d = mur_d;
	return (size);
}
