#include "main.h"

/************** FUNCTIONS TO PRINT CHARS *************************/

/**
 * print_char - Prints character
 * @types: List a of arguments to pass to func
 * @buffer: Buffer array to handle printing
 * @flags:  Computes available active flags
 * @width: Buffer Width
 * @precision: Precision specifications
 * @size: Buffer size specifiers
 * Return: Number of printed characters
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******************** FUNCTIONS PRINT A STRING *************************/
/**
 * print_string - function to prints a string
 * @types: arguments
 * @buffer: Buffer array for print handling
 * @flags: active flags
 * @width: get buffer width.
 * @precision: Precision specification
 * @size: Buffer size specifier
 * Return: printed string
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lenn = 0, g;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lenn] != '\0')
		lenn++;

	if (precision >= 0 && precision < lenn)
		lenn = precision;

	if (width > lenn)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lenn);
			for (g = width - lenn; g > 0; g--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (g = width - lenn; g > 0; g--)
				write(1, " ", 1);
			write(1, &str[0], lenn);
			return (width);
		}
	}

	return (write(1, str, lenn));
}

/************************* PRINT PERCENTAGE SIGN *************************/
/**
 * print_percent - Prints a percentage sign to std out
 * @types: arguments list
 * @buffer: Buffer array for print handling
 * @flags: Calculates active flags
 * @width: Bufferwidth.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: % character
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

/********************* PRINT INTEGERS ***********************/
/**
 * print_int - Print integers
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Computes available active flags
 * @width: get buffer width.
 * @precision: Precision specification
 * @size: buffer size specifier
 * Return: printed integers
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[g--] = (num % 10) + '0';
		num /= 10;
	}

	g++;

	return (write_number(is_negative, g, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints binary numbers an unsigned number
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: buffer width.
 * @precision: Precision specification
 * @size: buffer size specifier
 * Return: printed binary code.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, g, sum;
	unsigned int a[32];
	int incr;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (g = 1; g < 32; g++)
	{
		m /= 2;
		a[g] = (n / m) % 2;
	}
	for (g = 0, sum = 0, incr = 0; g < 32; g++)
	{
		sum += a[g];
		if (sum || g == 31)
		{
			char z = '0' + a[g];

			write(1, &z, 1);
			incr++;
		}
	}
	return (incr);
}
