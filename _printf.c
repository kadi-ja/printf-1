#include "main.h"

/**
 * _printf - function like printf
 * @format: string whit format to print
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	int char_printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	char_printed = print_format(format, args);

	va_end(args);
	return (char_printed);
}
