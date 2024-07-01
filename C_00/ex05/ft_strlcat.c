unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int len_dest = ft_strlen(dest);
    int len_src = ft_strlen(src);
    int i = 0;

    if(len_dest > size)
        return(len_src + size);
    while(src[i])
    {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[i + len_dest] = '\0';
    return(len_dest + len_src);
}
