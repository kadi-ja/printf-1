#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h>

/**
 * _printf-2 - The function that produces the output based on the format specifier
 * @format - this is the format specifier
 * return: length of the print string
 */

int _printf(const char *format, ...)
{
	int len2, len;
	va_list ap;

	va_start(ap, format);
	while (*format != "\0")
	{
		if (*format == "\0")
		{
			format++;
			if (*format == "c")
			{
				format++;
				if (*format == "c")
				{
					len2 = c_handler(va_arg(ap, int));
					len += len2;
					format++;
				}
				else if (*format == "s")