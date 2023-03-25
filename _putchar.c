#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	int written_chars = 0;

	written_chars = write(1, &c, 1);
	if (written_chars < 1)
		exit(100);
	else
		return (written_chars);
}
