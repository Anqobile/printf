#include "main.h"

/**
 * rot13 - encrypts string with rot13 style format
 * @list: string to encrypt
 * Return: modified (encrypted) string
 */

char *rot13(va_list list)
{
	int i;
	char *str;
	char *newstr;

	str = va_arg(list, char *);

	newstr = malloc(sizeof(char) *
			(_strlen(str) + 1));
	if (newstr == NULL)
		return (NULL);

	/* iterate str and assign rot13 characters to newstr */
	for (i = 0; str[i] != '\0'; i++) /* while (str[i] != '\0') */
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			newstr[i] = str[i] + 13;
		}
		else
			(newstr[i] = str[i]);
		/* i++; */
	}
	newstr[i] = '\0';

	return (newstr);
}


