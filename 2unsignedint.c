#include <stdio.h>

/**
 * printBinary - the unsigned int argument is converted to binary
 * Return: Always 0 (sucess)
 */

void printBinary(unsigned int number)
{
    if (number > 1)
    {
        printBinary(number / 2);
    }
    printf("%u", number % 2);
}

int main() 
{
    unsigned int number = 42;

    printf("%b\n", number);

    return 0;
}
