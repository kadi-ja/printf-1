#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
*percentage_handler - A function to print a %
*@list: list of variadic argument list
*Return: length of the printed string
*/

int percentage_handler(va_list list)
{
	if (list)
	{
		va_arg(list, int);
		return (_putchar('%'));
	}
	else
		return (0);
}
