#include "main.h"
/**
 * print_uns_int - prints unsigned integer
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i, num_digits = 0;
	unsigned int tmp;
	char *buffer;

	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		num_digits++;
	}

	buffer =  malloc(num_digits + 1);
	if (buffer == NULL)
		return (-1);

	i = num_digits - 1;
	do {
		buffer[i] = '0' + (n % 10);
		n /= 10;
		i--;
	} while (n > 0);

	buffer[num_digits] = '\0';

	for (i = 0; i < num_digits; i++)
		_write(buffer[i]);

	free(buffer);

	return (num_digits);
}

/**
 * print_octal - prints unsigned octal
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str;
	int len = 0, digit_count = 1;
	unsigned int tmp = num;


	while (tmp /= 8)
		digit_count++;

	str = malloc(sizeof(char) * (digit_count + 1));

	if (str == NULL)
		return (-1);

	do {
		str[len++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);

	while (len > 0)
	{
		len--;
		if (_write(str[len]) != 1)
		{
			free(str);
			return (-1);
		}
	}
	free(str);
	return (len);
}



