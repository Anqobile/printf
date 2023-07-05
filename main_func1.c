#include "main.h"

/**************** PRINT UNSIGNED INT *************************/
/**
 * print_unsigned - Prints unsigned numbers
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: buffer width
 * @precision: Precision specification
 * @size: buffer size specifier
 * Return: unsigned int.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[g--] = (num % 10) + '0';
		num /= 10;
	}

	g++;

	return (write_unsgnd(0, g, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL FORMAT  ************/
/**
 * print_octal - Prints un-int in octal notation
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Computes active flags
 * @width: get buffer width
 * @precision: Precision specification
 * @size: buffer size specifier
 * Return: octal number
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int g = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[g--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[g--] = '0';

	g++;

	return (write_unsgnd(0, g, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get buffer width
 * @precision: buffer Precision specification
 * @size: Size specifier
 * Return: Number printed in hex formar
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints a number in upper hexadecimal notation
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Computes active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: upper hex
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEX (hexadecimal) NUM IN LOWER OR UPPER **************/
/**
 * print_hexa ;- prints hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: lower hex format
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int g = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_num = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[g--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[g--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[g--] = flag_ch;
		buffer[g--] = '0';
	}

	g++;

	return (write_unsgnd(0, g, buffer, flags, width, precision, size));
}
