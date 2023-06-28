#include "main.h"

/**
 * get_width - Computes buffer width for print
 * @format: Format string in which to print the arguments.
 * @d: List of args to print.
 * @xlist: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *d, va_list xlist)
{
	int mur_d;
	int width = 0;

	for (mur_d = *d + 1; format[mur_d] != '\0'; mur_d++)
	{
		if (is_digit(format[mur_d]))
		{
			width *= 10;
			width += format[mur_d] - '0';
		}
		else if (format[mur_d] == '*')
		{
			mur_d++;
			width = va_arg(xlist, int);
			break;
		}
		else
			break;
	}
	*d = mur_d - 1;
	return (width);
}
