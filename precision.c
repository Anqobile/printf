#include "main.h"

/**
 * get_precision - Computes the precision for printing
 * @format: Formatted string to print the arguments
 * @d: Arguments list to be printed.
 * @xlist: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *d, va_list xlist)
{
	int mur_d = *d + 1;
	int precision = -1;

	if (format[mur_d] != '.')
		return (precision);
	precision = 0;
	for (mur_d += 1; format[mur_d] != '\0'; mur_d++)
	{
		if (is_digit(format[mur_d]))
		{
			precision *= 10;
			precision += format[mur_d] - '0';
		}
		else if (format[mur_d] == '*')
		{
			mur_d++;
			precision = va_arg(xlist, int);
			break;
		}
		else
			break;
	}

	*d = mur_d - 1;
	return (precision);
}
