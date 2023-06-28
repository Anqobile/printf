#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmtt - Struct op
 * @fmtt: The format.
 * @fn: The function associated.
 */

struct fmtt
{
	char fmtt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmtt: The format.
 * @fm_tt: The function associated.
 */

typedef struct fmtt fmtt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmtt, int *ind,
		va_list xlist, char buffer[], int flags, int width, int precision, int
		size);


/****************** FUNCTIONS ******************/
/* Print characters and strings */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Prints numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);int print_hexa_upper(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int
		size);

/* Prints non printable characters */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Memory address printer */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Handles other specifiers */

int get_flags(const char *format, int *d);
int get_width(const char *format, int *d, va_list xlist);
int get_precision(const char *format, int *d, va_list xlist);
int get_size(const char *format, int *d);

/*Prints all strings in reverse*/

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot13*/

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/****************** WIDTH_HANDLER **************/

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
		int length, char paddition, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char paddition, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size);

/****************** UTILITIES ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

