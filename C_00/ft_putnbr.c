#include <unistd.h>

void ft_putnbr(int nb)
{
    size_t n;

    if(nb < 0)
    {
        ft_putchar('-');
        n = -nb;
    }
    else
        n = nb;
    if(nb > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}
