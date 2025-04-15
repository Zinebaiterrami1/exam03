// #include "ft_printf.h"

// int ft_putstr(char *str, int* count)
// {
//     int i;

//     i = 0;
//     while(str)
//     {
//         count += write(1, &str[i], 1);
//         i++;
//     }
//     return (count);
// }

// int ft_putchar(char c, int* count)
// {
//     count += write(1, &c, 1);
//     return(count);
// }
 
// void ft_putnbr(int nb, int *count)
// {
//     count = 0;
//     if(nb > 9)
//     {
//         ft_putnbr(nb / 10, 0);
//         ft_putnbr(nb % 10, 0);
//     }
//     else if(nb < 10)
//         ft_putchar(nb + 48, &count);
// }

// void ft_puthex(int nb, int* count)
// {
//     if(nb >= 16)
//     {
//         ft_puthex(nb / 16, 0);
//         ft_puthex(nb % 16, 0);
//     }
//     if(nb < 10)
//         ft_putchar(nb + 48, );
//     else if(nb < 16)
//         ft_putchar(nb + 87);
// }