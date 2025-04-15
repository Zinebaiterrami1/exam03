#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

void    ft_putnbr(int nbr, int *count)
{
    char    c;

    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10, count);
        c = (nbr % 10) + '0';
        *count += write(1, &c, 1);
    }
    else if (nbr == -2147483648)
        *count += write(1, "-2147483648", ft_strlen("-2147483648"));
    else if (nbr < 0)
    {
        nbr = -nbr;
        *count += write(1, "-", 1);
        ft_putnbr(nbr, count);
    }
    else
    {
        c = nbr + '0';
        *count += write(1, &c, 1);
    }
}

// void    ft_puthex(unsigned int nbr, int *count)
// {
//     char    c;
//     unsigned int     n;

//     if (nbr >= 10)
//     {
//         if (nbr >= 16)
//             ft_puthex(nbr / 16, count);
//         n = nbr % 16;
//         if (n >= 10 && n <= 15)
//         {
//             c = n - 10 + 'a';
//             *count += write(1, &c, 1);
//         }
//         else
//         {
//             c = n + '0';
//             *count += write(1, &c, 1);
//         }
//     }
//     else
//     {
//         c = nbr + '0';
//         *count += write(1, &c, 1);
//     }
// }

void ft_puthex(int nb, int* count)
{
    char c;

    if(nb >= 16)
    {
        ft_puthex(nb / 16, count);
        ft_puthex(nb % 16, count);
    }
    if(nb < 10)
    {
        c = nb + 48;
        *count += write(1, &c, 1);
    }
    else if(nb < 16)
    {
        c = nb + 87;
        *count += write(1, &c, 1);
    }
}

void    ft_putstr(char *str, int *count)
{
    int     i;

    if (!str)
    {
        *count += write(1, "(null)", ft_strlen("(null)"));
        return ;
    }
    i = 0;
    while (str[i])
    {
        *count += write(1, &str[i], 1);
        i++;
    }
}

int ft_printf(char *str, ...)
{
    int d_res;
    int x_res;
    char *s_res;
    int count;
    char    specifier;
    va_list    args;

    va_start(args, str);
    count = 0;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            specifier = *str;
            if (specifier == 'd')
            {
                d_res = va_arg(args, int);
                ft_putnbr(d_res, &count);
            }
            else if (specifier == 'x')
            {
                x_res = va_arg(args, int);
                ft_puthex(x_res, &count);
            }
            else if (specifier == 's')
            {
                s_res = va_arg(args, char *);
                ft_putstr(s_res, &count);
            }
        }
        else
            count += write(1, str, 1);
        str++;
    }
    va_end(args);
    return (count);
}

int main()
{
    int count;
    int std_count;

    std_count = printf("std --> %d////%x////%s///xjhdjksdg\n", INT_MIN, 42, "hhhhhhhhhhhhhhhhhhhhhhhhhh");
    count = ft_printf("ana --> %d////%x////%s///xjhdjksdg\n", INT_MIN, 42, "hhhhhhhhhhhhhhhhhhhhhhhhhh");
    printf("std_count --> %d, count --> %d\n", std_count, count);
}
