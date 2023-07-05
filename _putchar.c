#include <unistd.h>
/**
 * _putchar - write the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success, the function returns 1.
 * On error, the function returns -1 and errno is set.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
