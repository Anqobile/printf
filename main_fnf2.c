#include "main.h"

/****************** PRINTING  POINTERS ******************/
/**
 * print_pointer - Prints the value of a pointer to a variable
 * @types: Argument list
 * @buffer: Buffer array
 * @flags: Computes active flags
 * @width: gets buffer width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of printed characters.
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
		buffer[ind--] = map_to[num_addrs % 16];num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;

	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/******************** PRINT NON PRINTABLE CHARACTERS ********************/
/**
 * print_non_printable - Prints ASCII codes in hexadecimal of non printable chars
 * @types: Arguments list
 * @buffer: Buffer array
 * @flags: Calculates flacts that are active
 * @width: gets buffer width
 * @precision: Precision specs
 * @size: Size specifier
 * Return: Number of printed characters
 */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *strng = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strng == NULL)
		return (write(1, "(null)", 6));
	while (strng[x] != '\0')
	{
		if (is_printable(strng[x]))
			buffer[x + offset] = strng[x];else
				offset += append_hexa_code(strng[x], buffer, x + offset);
		x++;
	}
	buffer[x + offset] = '\0';
	return (write(1, buffer, x + offset));
}

/************************* PRINT CHARS IN REVERSE *************************/
/**
 * print_reverse - Print string in reverse.
 * @types: List of arguments to be used
 * @buffer: Buffer array for print
 * @flags: Calculates active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of printed characters
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *strng;
	int x, count = 0;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	strng = va_arg(types, char *);
	if (strng == NULL)
	{
		UNUSED(precision);
		strng = ")Null(";
	}
	for (x = 0; strng[x]; x++)
		;
	for (x = x - 1; x >= 0; x--)
	{char z = strng[x];
		write(1, &z, 1);
		count++;
	}
	return (count);
}

/*************** PRINT A STRING IN ROT1 FORMAT3 ****************/
/**
 * print_rot13string - Print a string in rot13 format.
 * @types: Arguments list
 * @buffer: Buffer array for print handling
 * @flags: Calculates active flags
 * @width: get width of buffer
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Numbers of printed chars
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *strng;
	unsigned int q, p;
	int count = 0;
	char ins[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outs[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	strng = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strng == NULL)
		strng = "(AHYY)";
	for (q = 0; strng[q]; q++)
	{
		for (p = 0; ins[p]; p++)
		{
			if (ins[p] == strng[q])
			{
				x = outs[p];
				write(1, &x, 1);
				count++;break;
			}
		}
		if (!ins[p])
		{
			x = strng[q];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
