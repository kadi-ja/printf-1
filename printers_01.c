#include "main.h"

/**
 * print_chr - Prints a character to stdout
 * @buf: array buffer of max size 1024
 * @pos: the current position of the buffer
 * @args: A va_list containing the character to print
 * Return: The number of characters printed
 */

int print_chr(va_list args, char *buf, size_t *pos)
{
	char c = va_arg(args, int);

	write_char_to_buf(c, buf, pos);
	return (1);
}

/**
 * print_str - Prints a string to stdout
 * @buf: array buffer of max size 1024
 * @pos: the current position of the buffer
 * @args: A va_list containing the string to print
 * Return: The number of characters printed
 */
int print_str(va_list args,  char *buf, size_t *pos)
{
	int count = 0;
	char *s = va_arg(args, char *);

	if (!s)
		s = "(null)";

	while (*s)
	{
		write_char_to_buf(*s, buf, pos);
		s++;
		count++;
	}

	return (count);
}

/**
 * print_percent - Prints a percent sign to stdout
 * @buf: array buffer of max size 1024
 * @pos: the current position of the buffer
 * @args: A va_list containing the string to print
 * Return: The number of characters printed
 */
int print_percent(va_list args, char *buf, size_t *pos)
{
	(void)args;
	write_char_to_buf('%', buf, pos);
	return (1);
}
