#include "main.h"

/**
 * write_buffer - writes the buffer to stdout
 * @buf: pointer to the buffer
 * @pos: the current position in the buffer
 * Return: the number of characters printed
 */
int write_buffer(char *buf, size_t pos)
{
	int char_printed = write(1, buf, pos);

	return (char_printed);
}

/**
 * write_char_to_buf - add char to the buffer
 * @c: char to be added
 * @buf: pointer to the buffer
 * @pos: the current position in the buffer
 * Return: the number of characters printed
 */

void write_char_to_buf(char c, char *buf, size_t *pos)
{
	buf[*pos] = c;
	(*pos)++;
	if (*pos == 1024)
	{
		write_buffer(buf, *pos);
		*pos = 0;
	}
}

