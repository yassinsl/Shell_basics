int ft_iterative_factorial(int nb)
{
    int result = 1;

    if(nb <= 0)
        return(0);
    while(nb > 0)
        result *= nb--;
    return result;
}
int main()
{
    int num = 4;

   printf("%d\n", ft_iterative_factorial(num));
    return(0);
}
