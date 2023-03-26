#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct sp - Struct print_t
 * @sp: The specifier
 * @f: The function associated
 */
typedef struct sp
{
	char *sp;
	int (*f)(va_list, char *buf, size_t *pos);
} print_t;


int print_chr(va_list args, char *buf, size_t *pos);
int print_str(va_list, char *buf, size_t *pos);
int print_percent(va_list, char *buf, size_t *pos);
int _printf(const char *format, ...);
int (*get_sp_func(const char *format))(va_list, char *buf, size_t *pos);
int write_buffer(char *buf, size_t pos);
void write_char_to_buf(char c, char *buf, size_t *pos);

#endif
