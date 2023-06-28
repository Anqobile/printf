#include "main.h"

/**
 * handle_print - Prints args based on their type
 * @fmtt: Formatted string to print the arguments.
 * @xlist: List of arguments to be printed.
 * @ind: indicator
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width of buffer.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmtt, int *ind, va_list xlist, char buffer[],
		int flags, int width, int precision, int size)
{
	int x, unknow_len = 0, printed_chars = -1;
	fmtt_t fmtt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x',
								   print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S',
								       print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (x = 0; fmtt_types[x].fmtt != '\0'; x++)
		if (fmtt[*ind] == fmtt_types[x].fmtt)
			return (fmtt_types[x].fn(xlist, buffer, flags, width,
						precision, size));
	if (fmtt_types[x].fmtt == '\0')
	{
		if (fmtt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmtt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmtt[*ind] != ' ' && fmtt[*ind] != '%')
				--(*ind);
			if (fmtt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmtt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
