#include "main.h"

/**
 * get_func - collects the needed function
 * @i: function identifire
 * Return: Pointer to the collected function
 */

char* (*get_func(char i))(va_list)
{
	int m = 0;

	print keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', itob},
		{'R', rot13},
		{'r', rev_string},
		{'o', itoOctal},
		{'\0', NULL}
	};

	while (keys[m].id != '\0')
	{
		if (keys[m].id == i)
			return (keys[m].func);
		m++;
	}
	return (NULL);
}

/**
 * create_buffer - buffer to hold string until ready to be printed
 * Return: pointer to created.
 */

char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * write_buffer - prints buffer, frees the buffer and va_list
 * @buffer: buffer holding printables
 * @len: length of string
 * @list: va_list
 */

void write_buffer(char *buffer, int len, va_list list)
{
	char *barfar; /* bar + far = buffer (barfar). Sounds cool doesn't it? */

	barfar = realloc(buffer, len); /* realloc to correct size of buffer */
	write(1, barfar, len); /* print buffer contents */

	free(barfar); va_end(list);
}
