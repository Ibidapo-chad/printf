#ifndef HOLB_H
#define HOLB_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct convert - defines a layed out structure for symbols and functions
 * @sym: operator symbol
 * @f: associated function
 */
typedef struct convert
{
	char *sym;
	int (*f)(va_list);
}crt;

/* prototype functions */
int _printf(const char *format, ...);

int _putchar(char);
int parser(const char *format, conver_t f_list[], va_list arg_list);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

/*Helper functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);


#endif
