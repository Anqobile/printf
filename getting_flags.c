#include "main.h"

/**
 * get_flags - Computess active flags
 * @format: Formatted string to print args
 * @d: take a parameter.
 * Return: Flags if available.
 */

int get_flags(const char *format, int *d)
{
	int p, mur_d;
	int flagz = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE,
		0};
	for (mur_d = *d + 1; format[mur_d] != '\0'; mur_d++)
	{
		for (p = 0; FLAGS_CH[p] != '\0'; p++)
			if (format[mur_d] == FLAGS_CH[p])
			{
				flagz |= FLAGS_ARR[p];
				break;
			}
		if (FLAGS_CH[p] == 0)
		break;
	}
	*d = mur_d - 1;
	return (flagz);
}
