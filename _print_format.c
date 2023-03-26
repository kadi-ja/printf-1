#include "main.h"
/**
  * print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */

int print_format(const char *format, va_list args)
{
	int count = 0;
	int (*sp_func)(va_list);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			while (*format == ' ')
				format++;
			if (*format == '%')
				count += _putchar(*format);

			sp_func = get_sp_func(format);

			if (sp_func)
				count +=  sp_func(args);
			else
				{
					count += _putchar('%');
					if (*format)
						count += _putchar(*format);
				}
		}
		else
			count += _putchar(*format);
		format++;
	}
	return (count);
}

