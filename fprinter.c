#include "main.h"

/**
 * check_buffer_overflow - checks buffer overflow if writing over buffer space.
 * @buffer: buffer with string to be printed
 * @len: position in buffer
 * Return: length position
 */

int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * _printf - custom version of the standard printf function
 * @format: string with all identifiers
 * Return: expand strings with identifiers
 */

int _printf(const char *format, ...)
{
	int len = 0, total_len = 0, k = 0, ; = 0;
	va_list list;
	char *buffer, *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);

	va_start(list, format);

	while (format[k] != '\0')
	{
		if (format[k] != '%')
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] format[k++];
			total_len++;
		}
		else
		{
			k++;
			if (format[k] == '\0') /* handle those ending % */
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[k] == '%') /* for double %'s */
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[k];
				total_len++;
			}
			else
			{
				f = get_func(format[k]) /* collection function */
				if (f == NULL) /* handle fake identifier */
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] '%'; total_len++;
					buffer[len++] = format[k]; total_len++;
				}
				else /* copy to buffer */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[k] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					l = 0;
					while (str[l] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[l];
						total_len++;
						l++;
					}
					fre(str);
				}
			} k++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}

/**
 * test - test program above
 * Return: 0 on sucess
 */

int test(void)
{
	_printf("\n\n\nHere's some explamples of what you could do with this custom_printf function!\n\n\n");
	sleep(1);
	_printf("\nPrinting Strings, Characters, and Numbers...... %s%c%drld\n\n", "Hello", 'W', 0);
	sleep(1);
	_printf("Printing Reverse...... %r\n\n", "Hello");
	sleep(1);
	_printf("Printing Binary (base 2)...... %b \n\n", "Hello");
	sleep(1);
	_printf("Printing Octal (base 8)...... %o \n\n", "Hello");
	sleep(1);
	_printf("Printing Rot13 (encrpty)...... %R \n\n", "Hello");
	sleep(1);
	_printf("\n\n      = ) \n\n\n");
	return (0);
}
