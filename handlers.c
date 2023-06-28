#include "main.h"

/************************* WRITE HANDLER ************************/
/**
 * handle_write_char - Prints a formattedstring
 * @c: types of characters
 * @buffer: Buffer array to handle print
 * @flags: Calculates flags.
 * @width: get width of buffer..
 * @precision: precision specifie for the stringr
 * @size: buffer size specifier
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0;
	char paddition = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		paddition = '0';
	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = paddition;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width -
						1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/******** WRITING A NUMBER ********/
/**
 * write_number - Prints a string to stdout
 * @is_negative: List of arguments.
 * @ind: character types.
 * @buffer: Array of buffer to handle print
 * @flags: Calculates active flags in buffer size.
 * @width: get width of buffer.
 * @precision: precision specifier
 * @size: Buffer size specifier
 * Return: Number of characters printed.
 */

int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char paddition = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddition = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flags, width, precision, length, paddition, extra_ch));
}

/**
 * write_num - Writes a number using a bufffer to stdout
 * @ind: Index the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @paddition: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */

int write_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char paddition, char extra_c)
{
	int x, paddition_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width
			== 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = paddition = ' ';
	if (prec > 0 && prec < length)
		paddition = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = paddition;
		buffer[x] = '\0';
		if (flags & F_MINUS && paddition == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1,
							&buffer[1], x - 1));
		}
		else if (!(flags & F_MINUS) && paddition == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], x - 1) + write(1,
						&buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && paddition == '0')
		{
			if (extra_c)
				buffer[--paddition_start] = extra_c;
			return (write(1, &buffer[paddition_start], x - paddition_start) +
					write(1, &buffer[ind], length - (1 - paddition_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes unsigned number
 * @is_negative: Indicates if the num is negative
 * @ind: Index the number starts in the buffer
 * @buffer: Array of characters
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written charters.
 */

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, x = 0;
	char paddition = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		paddition = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddition = '0';
	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = paddition;
		buffer[x] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1,
						&buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind],
						length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write memory address
 * @buffer: Arrays of characters
 * @ind: Index the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @paddition: Char representing the padding
 * @extra_c: Char representing extra character
 * @paddition_start: Index at which padding should start
 * Return: Number of written characters.
 */

int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char paddition, char extra_c, int paddition_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = paddition;
		buffer[x] = '\0';
		if (flags & F_MINUS && paddition == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1,
						&buffer[3], x - 3));
		}
		else if (!(flags & F_MINUS) && paddition == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], x - 3) + write(1,
						&buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && paddition == '0')
		{
			if (extra_c)
				buffer[--paddition_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[paddition_start], x - paddition_start) +
					write(1, &buffer[ind], length - (1 - paddition_start) -
						2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
