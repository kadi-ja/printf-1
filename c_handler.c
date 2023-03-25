#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * c_handler - A function that prints a char
 * @list: variadic argument list string to print
 * Return: length of printed string
 */

int c_handler(va_list list)
{
	char c;

	if (list)
	{
		c = va_arg(list, int);
		return (write(1, &c, 1));
	}
	return (0);
}
