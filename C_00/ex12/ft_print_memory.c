#include <unistd.h>

typedef unsigned long long size_l;
typedef unsigned char size_c;
 void print_hex(size_l nbr)
 {
      char *base = "0123456789abcdef";
  
      if(nbr >= 16)
          print_hex(nbr /16);
      write(1, &base[nbr % 16], 1);
}
void print_str(size_c *str, size_t size)
{
    int i = 0;

    while(i < size)
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
    write(1, ":", 1);
    while(i < size)
    {
     if(i % 2 == 0)
         write(1, " ", 1);
        if((size_t)data[i] < 16)
            write(1, "0", 1);
        print_hex((size_l)data[i]);
        i++;
    }
    while(i < 16)
    {
        if(i % 2 == 0)
            write(1, " ", 1);
        write(1, "  ", 2);
        i++;
    }
}
void print_add(size_l addr)
{
    int i = 0;
    size_l check = addr;

    while(i < 16)
    {
        if(check < 16)
            write(1, "0", 1);
        check /= 16;
        i++;
    }
    print_hex(addr);
}
void *ft_print_memory(void *addr, unsigned int size)
{
    int i = 0;
    size_t handle_len;
    size_c *arr = addr;

    while(size > i * 16)
    {
        if(size / 16 > i)
            handle_len = 16;
        else
            handle_len = size % 16;
        print_add((size_l)arr);
        print_data(arr, handle_len);
        write(1, " ", 1);
        print_str(arr, handle_len);
        arr += 16;
        i++;
    }
    return(addr);
}
int main(void)
{
    char str[] = "Bonjour les amin\n\tyassin";

    ft_print_memory(str, sizeof(str));
    return(0);
}
