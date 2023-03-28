#include "main.h"


/**
  * print_binary - Prints a int converted to binary
  * @args: A list of variadic arguments
  *
  * Return: The number of printed digits
  */

int print_binary(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		_write('1');
		n = -n;
		count++;
	}

	count += print_binary_helper(n);
	return (count);
}

/**
 * print_binary_helper - Prints the binary format of a given number
 * @n: The number to convert
 *
 * Return: The number of printed digits
 */
int print_binary_helper(int n)
{
	int count;

	if (n <= 1)
	{
		_write(n + '0');
		return (1);
	}

	count = print_binary_helper(n / 2);
	_write((n % 2) + '0');

	return (count + 1);
}


/**
 * print_uns_int - prints unsigned integer
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_int(va_list args)
{
	unsigned int n = va_arg(args, int), i = 1, divi = 1, j;
	unsigned int m = n;
	unsigned int tmp = n;

	if (n < 1)
	{
		_write('0' + 0);
		return (1);
	}
	if (n >= 1 && n <= 9)
		_write('0' + n);
	else
	{
		while (m >= 10)
		{
			m = m / 10;
			i++;
		}
		for (j = i; j > 1; j--)
			divi = divi * 10;
		for (j = 1; j <= i; j++)
		{
			m = tmp / divi;
			tmp = tmp - (m * divi);
			divi = divi / 10;
			_write('0' + m);
		}
	}
	return (i);
}

/**
 * print_octal - prints unsigned octal
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
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
		y = y / 8;
	ptr = malloc(sizeof(char) * j);
	if (ptr == NULL)
		return (-1);
	for (i = 0; x > 0; i++)
	{
		res = x % 8;
		x = x / 8;
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



