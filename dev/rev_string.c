#include "main.h"

/**
 * rev_string - reverse a string (reverse string character)
 * @list: string to be reversed
 * Return: reversed string (output)
 */

char *rev_string(va_list list)
{
	char *revs;
	char *str;
	int i = 0, len, m;

str = va_arg(list, char*); /* stores argument to access only once */
if (str == NULL)
	str = ")llun(";

len = _strlen(str);

revs = malloc(sizeof(char) * (len + 1)); /* mallc new variable */
if (revs == NULL)
	return (NULL);

for (m = (len - 1); m >= 0; m--)
{
	revs[i++] = str[m];
	}
revs[i] = '\0';

return (revs); /* Reversed string */
}
