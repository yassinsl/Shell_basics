int ft_fibonacci(int index)
{
    if(index < 0)
        return(0);
    else if(index < 2)
        return(index);
    else
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main()
{
    int i = 0;

    while(i < 5)
    {
        printf("%d  ", ft_fibonacci(i));
        i++;
    }
    return(0);
}
