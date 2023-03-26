#include "main.h"
/**
 * _printf - function like printf
 * @format: string whit format to print
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	int char_printed = 0, (*sp_func)(va_list,  char *buf, size_t *pos);
	va_list args;
	char *buf = malloc(1024 * sizeof(char));
	size_t pos = 0;

	va_start(args, format);
	if (!format || !buf)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			sp_func = get_sp_func(format);
			if (!sp_func)
			{
				write_char_to_buf('%', buf, &pos);
				if (*format)
					write_char_to_buf(*format, buf, &pos);
				char_printed += 2;
			}
			else
				char_printed += sp_func(args, buf, &pos);
		}
		else
		{
			write_char_to_buf(*format, buf, &pos);
			char_printed++;
		}
		format++;
	}
	if (pos)
		write_buffer(buf, pos);
	va_end(args);
	free(buf);
	return (char_printed);
}
