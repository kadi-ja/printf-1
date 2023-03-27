#include "main.h"

/**
* get_sp_func- get the correct function
* @format: format specifier
* Return: pointer to the correct function
**/

int (*get_sp_func(char format))(va_list)
{
	int i;
		print_t sp[] = {
		{'c', _print_a_char},
		{'s', _print_a_string},
		{'u', print_uns_int},
		{'o', print_octal},
		{'x', print_uns_hex},
		{'X', print_uns_HEX},
		{'S', print_S},
		{'p', print_p},
		{'i', print_int_val},
		{'d', print_dec},
		{'\0', NULL}
	};

	for (i = 0; sp[i]._type; i++)
	{
		if (format == sp[i]._type)
		{
			return (sp[i].f);
		}
	}
	return (NULL);
}
