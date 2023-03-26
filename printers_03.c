#include "main.h"

/**
 * print_uns_hex - Prints unsigned hex
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_hex(va_list args)
{
	unsigned int x = va_arg(args, int);
	int res, i, j, count = 0;
	char *ptr;
	unsigned int  y = x;

	if (x < 1)
	{
		_write('0' + 0);
		return (1);
	}
	for (j = 0; y > 0; j++)
		y = y / 16;
	ptr = malloc(sizeof(char) * j);
	if (ptr == NULL)
		return (-1);
	for (i = 0; x > 0; i++)
	{
		res = x % 16;
		x = x / 16;
		if (res > 9 && res < 16)
			ptr[i] = 39 + res;
		else
			ptr[i] = res;
		count++;
	}
	for (; i > 0; i--)
	{
		_write('0' + ptr[i - 1]);
	}
	free(ptr);
	return (count);
}


/**
 * print_uns_HEX - Prints unsigned HEX
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_HEX(va_list args)
{
	unsigned int x = va_arg(args, int);
	int res, i, j, count = 0;
	char *ptr;
	unsigned int  y = x;

	if (x < 1)
	{
		_write('0' + 0);
		return (1);
	}
	for (j = 0; y > 0; j++)
		y = y / 16;
	ptr = malloc(sizeof(char) * j);
	if (ptr == NULL)
		return (-1);
	for (i = 0; x > 0; i++)
	{
		res = x % 16;
		x = x / 16;
		if (res > 9 && res < 16)
			ptr[i] = 7 + res;
		else
			ptr[i] = res;
		count++;
	}
	for (; i > 0; i--)
	{
		_write('0' + ptr[i - 1]);
	}
	free(ptr);
	return (count);
}
