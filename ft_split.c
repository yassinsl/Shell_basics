#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
int is_in_charset(char c, char *charset)
{
    int j = 0;
    while (charset[j])
    {
        if (c == charset[j])
            return 1;
        j++;
    }
    return 0;
}

int ft_strlen(char *ptr)
{
	int i = 0;

	while(ptr[i])
		i++;
	return(i);
}
int ft_len_ch(char *str, char *op)
{
	int i = 0, j, count = 0;

	while(op[i])
	{
		j = 0;
		while(str[j])
		{
			if(str[j] == op[i])
				count++;
			j++;
		}
		i++;
	}
	return(count);
}
int ft_count_sp(char *str, char *charset)
{
	int i = 0, count = 0, j;

	while(str[i])
	{
		j = 0;
		while(charset[j])
		{
			if(str[i] == charset[j])
				return(i);
			j++;
		}
		i++;
	}
	return(i);
}
char **ft_split(char *str, char *charset)
{
	int len = ft_strlen(str);
	int size = len - ft_len_ch(str, charset) + 1;
	char **result = (char **)(malloc(sizeof(char *) * size));
	int i = 0, j,  k = 0;
	
	if(result == NULL)
		return(NULL);

	while(str[i])
	{
		while(str[i] && is_in_charset(str[i], charset))
			i++;
		if(str[i] == '\0')
			break;

		 len = ft_count_sp(&str[i], charset);
		 result[k] = (char *)(malloc(sizeof(char *) * (len + 1)));

		 if(result[k] == NULL)
			{
			//	while (k > 0)
                    		//	free(result[--k]);
				free(result);
				return(NULL);
			}
		j = 0;
		while(j < len)
		{
			result[k][j] = str[i + j];
			j++;
		}
		result[k][j] = '\0';
		k++;
		i += len;
	}
	result[k] = NULL;
	return(result);

}
int main(void)
{
	char *str = "yassin lahssini";
	char **ptr = ft_split(str, " ");
	int i = 0;

	for(; ptr[i]; i++)
		printf("%s\n", ptr[i]);
	free(ptr);
	return(0);
}
