# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *s, ...);
void *ft_putstr(char *str, int* count);
void ft_putnbr(int nbr);
void ft_puthex(int nb);
void ft_putchar(char c, int* count);

#endif