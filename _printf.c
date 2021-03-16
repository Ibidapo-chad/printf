#include "holberton.h"

/**
 * _printf -
 * @format: character string
 *
 * Return: an integer value
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int printed_chars;
	crt f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	printed_chars = parser(format, f_list, arg);
	va_end(arg);
	return (printed_chars);
}
