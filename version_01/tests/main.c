#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned int ui;
    void *addr;

    addr = (void *)0x7ffe637541f0;
    ui = (unsigned int)INT_MAX + 1024;
   _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
       _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
     _printf("%S\n", "Best\nSchool");

    printf("%d, %d\n",  _printf("Character:[%c]\n", 'H'), printf("Character:[%c]\n", 'H'));
    printf("%d, %d\n",   _printf("String:[%s]\n", "I am a string !"), printf("String:[%s]\n", "I am a string !"));
    return (0);
}