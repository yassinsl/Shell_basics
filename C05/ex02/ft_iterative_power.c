int ft_iterative_power(int nb, int power)
{
    int result = 1;

    if(power < 0)
        return(0);
    while(power)
    {
        result *= nb;
        power--;
    }
    return(result);
}
int main()
{
    int num = ft_iterative_power(2, 3);
    printf("%d\n", num);
}
