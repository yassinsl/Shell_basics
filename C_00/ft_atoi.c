#include <unistd.h>

int ft_atoi(char *str)
{
    int num = 0, sign = 1;

    while(*str && (*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    while(*str == '+' || *str == '-')
    {
        if(*str == '-')
            sign *= -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
        num = num * 10 + *str++ - '0';
    return(num * sign);
}
int main()
{
    char *str = "    ++--++12345bvvb3232";
    printf("%d\n", ft_atoi(str));
    return(0);
}
