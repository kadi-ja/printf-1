#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list c);
int print_string(va_list s);
int print_int_val(va_list inv);
int print_dec(va_list d_val);
int print_unsigned(va_list u);
int print_binary(va_list b);
int print_octal(va_list o);
int print_xlow(va_list x);
int print_Xcap(va_list X);
int print_add(va_list p);
int print_super(va_list S);
int print_reverse(va_list r);
int print_R(va_list R);
int print_buf(char *buf, unsigned int nbuf);

#endif
