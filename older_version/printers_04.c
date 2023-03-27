#include "main.h"

/**
* print_S - print non printable characters
* @args: string argument
* Return: bytes printed
**/
int print_S(va_list args)
{
	unsigned int i, count = 0, aux;
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			aux = str[i];
			_write('\\');
			_write('x');
			count = count + 2;
			if (aux > 0 && aux < 16)
			{
				_write('0');
				count++;
			}
			count = count + print_X(aux);
		}
		else
		{
			_write(str[i]);
			count++;
		}
	}
	return (count);
}


/**
* print_X - print number to hexa upper
* @x: number to print
* Return: number of bytes printed
**/
int print_X(unsigned long int x)
{
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

/**
* print_p - print pointer address
* @args: pointer arguments
* Return: number of bytes printed
**/
int print_p(va_list args)
{
	unsigned long n;
	int count = 0;

	n = va_arg(args, unsigned long int);

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	_write('0');
	_write('x');
	count = count + print_x(n) + 2;
	return (count);
}


/**
* print_x - print number to hexa lower
* @x: number to print
* Return: number of bytes printed
**/
int print_x(unsigned long int x)
{
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
