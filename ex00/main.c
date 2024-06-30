int ft_atoi(char *str);
void ft_putchar(char c);
void rush(int x, int y);

int main(int argc, char **argv)
{
    if(argc == 3)
        rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
    return(0);
}
