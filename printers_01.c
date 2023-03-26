#include "main.h"

/**
 * print_chr - Prints a character to stdout
 * @args: A va_list containing the character to print
 * Return: The number of characters printed
 */

int print_chr(va_list args)
{
	if (args)
	{
		char c = va_arg(args, int);

		write(1, &c, 1);
		return (1);
	}
	return (0);
}


/**
 * print_str - Prints a string to stdout
 * @args: A va_list containing the string to print
 * Return: The number of characters printed
 */
int print_str(va_list args)
{
	if (args)
	{
		int count = 0;
		char *s = va_arg(args, char *);

		if (!s)
			s = "(null)";

		while (*s)
		{
			write(1, s, 1);
			s++;
			count++;
		}
		return (count);
	}
	return (0);

}

/**
 * print_percent - Prints a percent sign to stdout
 * @args: list arguments
 * Return: The number of characters printed
 */
int print_percent(va_list args)
{
	if (args)
	{
		(void) args;
		write(1, "%",  1);
		return (1);
	}
	return (0);
}
