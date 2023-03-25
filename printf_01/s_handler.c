#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * s_handler - A function that prints the string
 * @list: variadic argument list
 * Return: length of the printed string
 *
 */

int s_handler(va_list list)
{
	char c;
	int i;

	if (list)
	{
		c = va_arg(list, int);

		for (i = 0; c != "\0"; i++)
		{
			write(1, &c, 1);
			c++;
		}
		return (i);
	}
	return (0);
}
