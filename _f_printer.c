#include "main.h"

/**
 * print_buffer - buffer printer prototypr
 * @buffer: Buffer
 * @buff_ind: buffer indicator
 */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - customised Printf function
 * @format: string formatter.
 * Return: Printed characters.
 */

int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list xlist;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(xlist, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, xlist);
			precision = get_precision(format, &x, xlist);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, xlist, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(xlist);
	return (printed_chars);
}

/**
 * print_buffer - Prints the buffer content if it exist
 * @buffer: Array of characters
 * @buff_ind: Index to add next char,  length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
