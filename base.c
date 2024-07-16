int ft_len(int num, int len)
{
    int max_len = 0;

    while(num > 0)
    {
        max_len++;
        num /= len;
    }
    return(max_len);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(!base_from || !base_from || !nbr)
        return(NULL);
    int len_base_to = ft_handle_error(base_to);
    int len_base_from = ft_handle_error(base_from);

    if(!len_base_from || !len_base_to)
        return(NULL);
    int num = ft_atoi_base(nbr, base_from, len_base_to);
    int len;

    if(number < 0)
        len = ft_len(-num) + 2;
    else
        len = ft_len(num) + 1;
    char *result = malloc(sizeof(char) * len);
    if(result == NULL)
        return(NULL);
    convert_base(num, len, result, base);
}
