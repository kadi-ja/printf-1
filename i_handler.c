#include <stdio.h>
#include "main.h"
#include <stdarg.h>
/**
*i_handler - A function to print a unsigned integer
*@list: variadic argument list string to print
*Return: length of the printed string
*/

int i_handler(va_list list)
{
	int l;

	if (list)
	{
		l = _putchar(va_arg(list, int));
		return (l);
	}
	return (0);
}
