#include "main.h"

/**
 * _write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write(char c)
{
	return (buffring(c));
}

int buffring(char c)
{
	char buffer[BUFFER_SIZE];
	int buf_idx = 0;

	buffer[buf_idx++] = c;

	if (buf_idx == BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		buf_idx = 0;
	}

	return (1);
}
