#include "main.h"
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
		l = _write(va_arg(list, int));
		return (l);
	}
	return (0);
}


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
		l = _write(va_arg(list, int));
		return (l);
	}
	return (0);
}


/**
 * b_handler - Converts an unsigned int to binary
 * @list: variadic argument list
 * Return: Number of characters printed
 */
int b_handler(va_list list)
{
    unsigned int num = va_arg(list, unsigned int);
    char buffer[32];
    int index = 0;

    if (num == 0)
    {
        _write('0');
        return (1);
    }

    while (num > 0)
    {
        buffer[index] = (num % 2) + '0';
        num /= 2;
        index++;
    }

    for (index--; index >= 0; index--)
        _write(buffer[index]);

    return (index + 1);
}
