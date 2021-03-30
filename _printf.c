#include "holberton.h"

/**
 * _printf - prints anything e.g strings, numbers.
 * @format: character string
 *
 * Return: an integer value
 */

int  _printf(char *format, ...)
{
	int CharacterCount = 0;
	int PrintInteger;
	char IntegerString[10];
	char *pPrintString;
	va_list VaList;

	va_start(VaList, format);

	while(*format)
	{
		if(*format == '%')
		{
			format++;
			switch(*format)
			{
			case 's':
				pPrintString = va_arg(VaList, char *);
				fputs(pPrintString, stdout);
			        format++;
				CharacterCount += strlen(pPrintString);
				break;
			case 'i':
				PrintInteger = va_arg(VaList, int);
				_itoa(PrintInteger, IntegerString, 10);
				fputs(IntegerString, stdout);
				format++;
				CharacterCount += strlen(IntegerString);
				break;
			case '%':
				_putchar('%');
			        format++;
				CharacterCount++;
				break;
			case '\0':
				break;
			default:
				_putchar('%');
				_putchar(*format);
				format++;
				CharacterCount +=2;
			}
		}
		else
		{
			_putchar(*format);
			format++;
			CharacterCount++;
		}
	}

	va_end(VaList);

	return CharacterCount;
}
