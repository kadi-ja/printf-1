#include "main.h"

/**
 * print_uns_hex - Prints unsigned hex
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int), tmp;
	int i = 0, j, digit, num_count = 0;
	char *buffer;

	tmp = num;
	while (tmp > 0)
	{
		tmp /= 16;
		num_count++;
	}

	buffer = malloc(sizeof(char) * (num_count + 1));

	if (buffer == NULL)
		return (-1);

	while (num > 0)
	{
		digit = num % 16;
		buffer[i++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		num /= 16;
	}

	if (i == 0)
		buffer[i++] = '0';

	buffer[i] = '\0';

	for (j = i - 1; j >= 0; j--)
		_write(buffer[j]);

	free(buffer);
	return (i);
}


/**
 * print_uns_HEX - Prints unsigned HEX
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int), temp;
	char *buffer;
	int len = 0, i, digit;

	if (num == 0)
	{
		_write('0');
		return (1);
	}


	temp = num;
	while (temp > 0)
	{
		len++;
		temp /= 16;
	}

	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (-1);
	i = len - 1;
	while (num > 0)
	{
		digit = num % 16;
		buffer[i] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
		num /= 16;
		i--;
	}

	buffer[len] = '\0';
	for (i = 0; buffer[i] != '\0'; i++)
		_write(buffer[i]);

	free(buffer);
	return (len);
}
