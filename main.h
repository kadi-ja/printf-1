#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct sp
{
	char _type;
	int (*f)(va_list args);
} print_t;

int (*get_sp_func(char format))(va_list);
int _write(char c);
int _printf(const char *format, ...);
int _print_a_char(va_list args);
int _print_a_string(va_list args);
int _print_format(const char *format, va_list args);
int print_uns_int(va_list args);
int print_octal(va_list args);
int print_uns_hex(va_list args);
int print_uns_HEX(va_list args);
int print_S(va_list args);
int print_X(unsigned long int x);
int print_x(unsigned long int x);
int print_p(va_list args);
int d_handler(va_list list);
int i_handler(va_list list);
int b_handler(va_list list);

#endif
