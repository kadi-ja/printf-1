#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
*d_handler - A function to print a char
*@list: variadic argument list string to print
*Return: length of the printed string
*/

int d_handler(va_list list)
{
	int l;

	if (list)
	{
		l = _putchar(va_arg(list, int));
		return (l);
	}
	return (0);
}
