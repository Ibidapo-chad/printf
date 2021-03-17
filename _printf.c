#include "holberton.h"

/**
 * _printf -
 * @pszFormatString: character string
 *
 * Return: an integer value
 */

int  printf_new(char *pszFormatString, ...)
{
	int CharacterCount = 0;
	int PrintInteger;
	char IntegerString[10];
	char *pPrintString;
	va_list VaList;

	va_start(VaList, pszFormatString);

	while(*pszFormatString)
	{
		if(*pszFormatString == '%')
		{
			pszFormatString++;
			switch(*pszFormatString)
			{
			case 's':
				pPrintString = va_arg(VaList, char *);
				fputs(pPrintString, stdout);
				pszFormatString++;
				CharacterCount += strlen(pPrintString);
				break;
			case 'i':
				PrintInteger = va_arg(VaList, int);
				_itoa(PrintInteger, IntegerString, 10);
				fputs(IntegerString, stdout);
				pszFormatString++;
				CharacterCount += strlen(IntegerString);
				break;
			case '%':
				_putchar('%');
				pszFormatString++;
				CharacterCount++;
				break;
			case '\0':
				break;
			default:
				_putchar('%');
				_putchar(*pszFormatString);
				pszFormatString++;
				CharacterCount +=2;
			}
		}
		else
		{
			_putchar(*pszFormatString);
			pszFormatString++;
			CharacterCount++;
		}
	}

	va_end(VaList);

	return CharacterCount;
}
/* int _printf(const char *format, ...)
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
	}*/
