#include "main.h"

/************************* PRINT A CHARACTER *************************/
/**
 * print_char - Prints a character to stdout
 * @types: Listof arguments
 * @buffer: Buffer array for print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision spec
 * @size: Size speci
 * Return: Number of printed characters
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision,
				size));
}

/************************* PRINTS A STRING *************************/
/**
 * print_string - Print string
 * @types: Listof arguments
 * @buffer: Buffer
 * @flags: Active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
		 int flags, int width, int precision, int size)
{
	int leng = 0, x;
	char *strng = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strng == NULL)
	{
		strng = "(null)";
		if (precision >= 6)
			strng = " ";
	}
	while (strng[leng] != '\0')
		leng++;
	if (precision >= 0 && precision < leng)
		leng = precision;
	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &strng[0], leng);
			for (x = width - leng; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - leng; x > 0; x--)
				write(1, " ", 1);
			write(1, &strng[0], leng);
			return (width);
		}
	}
	return (write(1, strng, leng));
}

/************************* PRINT PERCENTAGE SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: chars printed
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print integers
 * @types: Lists of arguments
 * @buffer: Buffer array fot print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int p = va_arg(types, long int);
	unsigned long int num;
	p = convert_size_number(p, size);
	if (p == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)p;if (p < 0)
	{
		num = (unsigned long int)((-1) * p);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}
	x++;
	return (write_number(is_negative, x, buffer, flags, width,
				precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints unsigned number
 * @types: argument list
 * @buffer: array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars print.
 */

int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, o, x, sum;
	unsigned int a[32];
	int count;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	o = 2147483648; /* (2 ^ 31) */
	a[0] = n / o;
	for (x = 1; x < 32; x++)
	{o /= 2;
		a[x] = (n / o) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
