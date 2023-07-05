
#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints pointer value to a variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates flags
 * @width: get buffer width
 * @precision: Precision specification
 * @size: Size specifier for buffer
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE THING *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable char
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags
 * @width: get width of buffer
 * @precision: Precision specification
 * @size: Size specifier for buffer
 * Return: hexadecimal
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[g] != '\0')
	{
		if (is_printable(str[g]))
			buffer[g + offset] = str[g];
		else
			offset += append_hexa_code(str[g], buffer, g + offset);

		g++;
	}

	buffer[g + offset] = '\0';

	return (write(1, buffer, g + offset));
}

/****************** PRINT STRING IN REVERSE ********************/
/**
 * print_reverse - Prints string in reverse.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Computes active flags
 * @width: buffer width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int g, incr = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (g = 0; str[g]; g++)
		;

	for (g = g - 1; g >= 0; g--)
	{
		char z = str[g];

		write(1, &z, 1);
		incr++;
	}
	return (incr);
}

/*************** PRINTS STRING IN ROT13 FORMAT ***************/
/**
 * print_rot13string - Print a string in rot13 encryption style
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get buffer width
 * @precision: Precision specification
 * @size: Size specifier of buffer
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int g, h;
	int incr = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (g = 0; str[g]; g++)
	{
		for(h = 0; in[h]; h++)
		{
			if (in[h] == str[g])
			{
				x = out[h];
				write(1, &x, 1);
				incr++;
				break;
			}
		}
		if (!in[h])
		{
			x = str[g];
			write(1, &x, 1);
			incr++;
		}
	}
	return (incr);
}
