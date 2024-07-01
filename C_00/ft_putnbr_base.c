#include <unistd.h>

void desplay(int nbr, int len, char *base)
{
    if(nbr < 0)
    {
        write(1, "-", 1);
        desplay(-nbr, len, base);
    }
    else if(nbr  >= len)
        desplay(nbr / len, len, base);
    write(1, &base[nbr % len], 1);
}
int ft_handle_error(char *base)
{
    int i = 0, j;

    while(base[i])
    {
        j = i + 1;

        while(base[j])
        {
            if(base[i] == base[j])
                return(0);
        j++;
        }
        i++;
    }
    if(i < 2)
        return(0);
    else
        return(i);
}
void ft_putnbr_base(int nbr, char *base)
{
    int len_base = ft_handle_error(base);

    if(!len_base)
        return ;
    desplay(nbr, len_base, base);
}
int main(void)
{
    ft_putnbr_base(42, "01");
}
