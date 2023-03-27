#include "main.h"

/**
 * print_int_val - this is to print the integer value
 * @inv: integer value to print
 *
 * Return: no of chars and digits printed
 */
int print_int_val(va_list inv)
{
	int a[10];
	int first_val, sec_val, third_val, sum, count;

	third_val = va_arg(inv, int);
	count = 0;
	sec_val = 1000000000;
	a[0] = third_val / sec_val;
	for (first_val = 1; first_val < 10; first_val++)
	{
		sec_val /= 10;
		a[first_val] = (third_val / sec_val) % 10;
	}
	if (third_val < 0)
	{
		_putchar('-');
		count++;
		for (first_val = 0; first_val < 10; first_val++)
			a[first_val] *= -1;
	}
	for (first_val = 0, sum = 0; first_val < 10; first_val++)
	{
		sum += a[first_val];
		if (sum != 0 || first_val == 9)
		{
			_putchar('0' + a[first_val]);
			count++;
		}
	}
	return (count);
}

/**
 * print_dec - this prints a decimal value
 * @d_val: decimal to print
 *
 * Return: number of chars and digits printed
 */
int print_dec(va_list d_val)
{
	int a[10];
	int first_val, sec_val, third_val, sum, count;

	third_val = va_arg(d_val, int);
	count = 0;
	sec_val = 1000000000;
	a[0] = third_val / sec_val;
	for (first_val = 1; first_val < 10; first_val++)
	{
		sec_val /= 10;
		a[first_val] = (third_val / sec_val) % 10;
	}
	if (third_val < 0)
	{
		_putchar('-');
		count++;
		for (first_val = 0; first_val < 10; first_val++)
			a[first_val] *= -1;
	}
	for (first_val = 0, sum = 0; first_val < 10; first_val++)
	{
		sum += a[first_val];
		if (sum != 0 || first_val == 9)
		{
			_putchar('0' + a[first_val]);
			count++;
		}
	}
	return (count);
}
