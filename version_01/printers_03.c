#include "main.h"

/**
 * print_uns_hex - Prints unsigned hex
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_hex(va_list args)
{
	return (print_unsigned_hex(args, 0));
}


/**
 * print_uns_HEX - Prints unsigned HEX
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_HEX(va_list args)
{
	return (print_unsigned_hex(args, 1));
}
