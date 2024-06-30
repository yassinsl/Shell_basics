void ft_putchar(char c);

int ft_atoi(char *str)
{
    int num = 0, sign = 1;

    while((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if(*str == '+' || *str == '-')
    {
        if(*str == '-')
            sign *= -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
        num = num * 10 + *str++ - '0';
    return(num * sign);
}
void rush(int x, int y)
{
    int j = 1;
    if (x <= 0 || y <= 0)
        return;
    while (j <= y)
    {
        int i = 1;
        while (i <= x)
        {
            if ((i == 1 || i == x) && (j == 1 || j == y))
                ft_putchar('o');
            else if ((i > 1 && i < x) && (j == 1 || j == y))
                ft_putchar('-');
            else if ((i == 1 || i == x) && (j > 1 && j < y))
                ft_putchar('|');
            else if ((i > 1 && i < x) && (j > 1 && j < y))
                ft_putchar(' ');
            i++;
        }
        ft_putchar('\n');
        j++;
    }
}
