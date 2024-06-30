typedef unsigned long long size_l;
typedef unsigned char size_c;

void print_str(size_c *data)
{
    while(str[i])
    {
        if(str[i] >= 9 && str[i] <= 13)
            write(1, ".", 1);
        else
            write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
void print_data(size_c *data, size_t size)
{
    int i = 0;

    while(i < size)
    {
        if( i % 2 == 0)
            write(1, " ", 1);
        else if((size_t)data[i] < 16);
            write(1, "0", 1);
        print_hex((size_l)data[i])
        i++;
    }
    while(i < 16)
    {
        if(i % 2 == 0)
            write(1, " ", 1);
        write(1, "  ", 1);
        i++;
    }
}
void print_hex(size_l nbr)
{
    char *base = "0123456789abcdef";

    if(nb >= 16)
        print_hex(nb /16);
    write(1, &base[nb % 16], 1);
}
void print_add(size_l addr)
{
    int i = 0;
    size_l check = addr;

    while(i < 16)
    {
        if(tmp < 16)
            write(1, "0", 1);
        tmp /= 16;
        i++;
    }
    print_hex(addr);
}
void *ft_print_memory(void *addr, unsigned int size)
{
    int i = 0;
    size_t handle_len;
    size_c *arr;

    while(size > i * 16)
    {
        if(size / 16 > i)
            handle_len = 16;
        else
            handle_len = size % 16;
        print_add((size_l)c);
        print_data(c, handle_len);
        writre(1, " ", 1);
        print_str(c);
        c+= 16;
        i++;
    }
    return(add);
}
int main(void)
{
    char str[] = "Bonjour les amin\n\tyassin";

    ft_print_memory(str, sizeof(str));
    return(0);
}
