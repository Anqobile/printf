#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* COLLECTOR FUNCTIONS */
char* (*get_func(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* functions to print */
int _printf(const char *format, ...);
char *print_s(va_list list);
char *print_c(va_list list);
char *print_d(va_list list);
char *itob(va_list list);
char *rot13(va_list list);
char *rev_string(va_list list);
char *itoOctal(va_list list);

/**
 * struct types - struct
 * @id: identifier of type to print
 * @func: ptr to functions that print
 */

typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

#endif
