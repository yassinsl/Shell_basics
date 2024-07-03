#include <unistd.h>

void ft_putnb(char num)
{
    if(num > '0')
        ft_putnb(num - 1);
    write(1, &num, 1);

}
int main(void)
{
    char c = '9';

    ft_putnb(c);
    return(0);
}
