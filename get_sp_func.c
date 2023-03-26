#include "main.h"

int (*get_sp_func(const char *format))(va_list, char *buf, size_t *pos)
{
        print_t sps[] = {
                {"c", print_chr},
                {"s", print_str},
                {"%", print_percent},
                {NULL, NULL}
        };
        int i;

        i = 0;


        while (sps[i].sp != NULL)
        {
                if (*(sps[i].sp) == *format)
                        return (sps[i].f);
                i++;
        }
        return (NULL);
}