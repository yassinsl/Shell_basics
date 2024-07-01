#include <unistd.h>

int ft_strlen(char *ptr)
{
    int i = 0;

    while(ptr[i])
        i++;
    return(i);
}
int get_value_index(char c, char *base)
{
    int i = 0;

    while(base[i])
    {
        if(base[i] == c)
            return(i);
        i++;
    }
    return(-1);
}
int ft_power(int len, int power)
{
    int result = 1;

    while(power)
    {
        result *= len;
        power--;
    }
    return(result);
}
int ft_handle_er(char *base)
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
int ft_atoi_base(char *str, char *base)
{
    int len_base = ft_handle_er(base);
    int len_str = ft_handle_er(str);
    int sign = 1, i = 0, len, value, num = 0, power = 0;
    if( len_base == 0)
        return(0);
    while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
            i++;
    }
    len = ft_strlen(&str[i]);
    while(len > 0)
    {
        value = get_value_index(str[i + len - 1], base);

        if(value == -1)
            return(0);
        num = num + value * ft_power(len_base, power);
        power++;
        len--;
    }
    return(num * sign);
}
int main()
{
    printf("%d", ft_atoi_base("-+-+101010","01"));
}
