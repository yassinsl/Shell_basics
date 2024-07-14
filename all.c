#include "ft_rush.h"

char	**ft_populate(char *arg, char **arr, int arg_len, int first_slot)
{
	int		i;
	int		j;
	int		arg_i;

	arg_i = 0;
	i = 0;
	while (i < (arg_len / 3) + first_slot)
	{
		j = 0;
		while (1)
		{
			if (j == 3)
			{
				arr[i++][j] = '\0';
				break ;
			}
			if (i == 0 && j == 0 && (arg_len % 3 == 2))
				arr[i][j++] = '0';
			while (i == 0 && (arg_len % 3 == 1) && j <= 1)
				arr[i][j++] = '0';
			arr[i][j++] = arg[arg_i++];
		}
	}
	return (arr);
}

char	**ft_allocate(char *arg)
{
	int		arr_len;
	int		i;
	int		first_slot;
	char	**arr;

	i = 0;
	arr_len = ft_strlen(arg);
	first_slot = ft_module(arg);
	if (!(arr = (char **)malloc((arr_len / 3 + first_slot) * sizeof(char *))))
		ft_puterror("Allocation Memory Error");
	while (i < (arr_len / 3) + first_slot)
	{
		if (!(arr[i] = (char *)malloc((3 + 1) * sizeof(char))))
		{
			ft_puterror("Allocation Memory Error");
			return (0);
		}
		i++;
	}
	arr = ft_populate(arg, arr, arr_len, first_slot);
	return (arr);
}

int		ft_read_words(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (!(str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z'))
	{
		i++;
	}
	while ((str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z'))
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

void	ft_engine_nest(char *digits, char **dictionary, int counter_rows)
{
	int		j;

	j = 0;
	while (j < 3)
	{
		if (digits[j] != '0')
		{
			if (j == 0)
				ft_first_digit(dictionary, digits[j], counter_rows);
			if (j == 1)
				ft_second_digit(dictionary, digits, counter_rows);
			if (j == 2 && digits[1] != '1')
				ft_third_digit(dictionary, digits[j], counter_rows);
		}
		j++;
	}
}

int		ft_engine(char *dictionary, char *str)
{
	char	**arr;
	char	**array;
	int		counter_rows;
	int		i;

	i = 0;
	arr = ft_allocate(str);
	array = ft_copy_dict_array(dictionary);
	counter_rows = ft_counter_rows(ft_read_dict(dictionary));
	if (arr[0][0] == '0' && arr[0][1] == '0' && arr[0][2] == '0')
	{
		ft_read_words(ft_strstr(array, counter_rows, "0"));
		return (0);
	}
	while (i < (ft_strlen(str) / 3 + ft_module(str)))
	{
		ft_engine_nest(arr[i], array, counter_rows);
		if (ft_strcmp(arr[i++], "000") != 0)
			ft_ord(array, counter_rows, ft_strlen(str) / 3 + ft_module(str), i);
	}
	free(arr);
	free(array);
	return (0);
}

int		ft_error(int argc, char *str)
{
	if (argc != 2 && argc != 3)
	{
		ft_puterror("Error\n");
		return (0);
	}
	if (!(ft_is_number(str)))
	{
		ft_puterror("Error\n");
		return (0);
	}
	if (ft_strlen(str) > 37)
	{
		ft_puterror("Dict Error\n");
		return (0);
	}
	return (1);
}

char	*ft_read_dict(char *dictionary)
{
	int		fd;
	char	*buf;

	buf = (char *)malloc(2000 * sizeof(char));
	fd = open(dictionary, O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Read error\n");
		return (0);
	}
	read(fd, buf, 1000);
	close(fd);
	return (buf);
}

int		ft_counter_rows(char *buf)
{
	int		j;
	int		rows;

	j = 0;
	rows = 0;
	while (buf[j])
	{
		if (buf[j++] == '\n')
			rows++;
	}
	return (rows);
}

char	**ft_alloc_array(char *buf)
{
	char	**array;
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	array = (char **)malloc(ft_counter_rows(buf) * sizeof(char *));
	while (i < ft_counter_rows(buf))
	{
		counter = 0;
		while (buf[j] != '\n')
		{
			counter++;
			j++;
		}
		j++;
		array[i++] = (char *)malloc((counter + 1) * sizeof(char));
	}
	return (array);
}

char	**ft_copy_dict_array(char *dictionary)
{
	int		i;
	int		j;
	int		k;
	char	*buf;
	char	**array;

	buf = ft_strdup(ft_read_dict(dictionary));
	i = 0;
	j = 0;
	array = ft_alloc_array(buf);
	while (i < ft_counter_rows(buf))
	{
		k = 0;
		while (buf[j] != '\n')
			array[i][k++] = buf[j++];
		array[i][k] = '\0';
		j++;
		i++;
	}
	free(buf);
	return (array);
}

int		ft_is_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			i++;
	}
	return (1);
}

int		ft_module(char *str)
{
	int		module;

	if (ft_strlen(str) % 3 > 0)
		module = 1;
	else
		module = 0;
	return (module);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*dest;

	src_len = ft_strlen(src);
	if ((dest = (char *)malloc(src_len * sizeof(char) + 1)) == NULL)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}

void	ft_first_digit(char **array, char digit, int counter_rows)
{
	char	tmp[3];

	tmp[0] = digit;
	tmp[1] = '\0';
	ft_read_words(ft_strstr(array, counter_rows, tmp));
	write(1, " ", 1);
	ft_read_words(ft_strstr(array, counter_rows, "100"));
	write(1, " ", 1);
}

void	ft_second_digit(char **array, char *digits, int counter_rows)
{
	char	tmp[3];
	int		j;

	j = 1;
	tmp[0] = digits[j];
	if (tmp[0] == '1')
		tmp[1] = digits[j + 1];
	else
		tmp[1] = '0';
	tmp[2] = '\0';
	ft_read_words(ft_strstr(array, counter_rows, tmp));
	write(1, " ", 1);
}

void	ft_third_digit(char **array, char digit, int counter_rows)
{
	char	tmp[3];

	tmp[0] = digit;
	tmp[1] = '\0';
	ft_read_words(ft_strstr(array, counter_rows, tmp));
	write(1, " ", 1);
}

void	ft_ord(char **array, int counter_rows, int max, int i)
{
	char	ord[38];
	int		o;
	int		k;

	o = 1;
	k = 1;
	while (o <= max - i)
	{
		ord[0] = '1';
		ord[k++] = '0';
		ord[k++] = '0';
		ord[k++] = '0';
		ord[k] = '\0';
		o++;
	}
	if (i != max)
	{
		ft_read_words(ft_strstr(array, counter_rows, ord));
		write(1, " ", 1);
	}
}

char	*ft_strstr(char **str_array, int array_l, char *to_find)
{
	int		str_i;
	int		find_i;
	int		index;

	str_i = 0;
	index = 0;
	find_i = 0;
	while (str_i < array_l)
	{
		while (to_find[find_i] && (to_find[find_i] == str_array[str_i][index]))
		{
			find_i++;
			index++;
			if (str_array[str_i][index] == ':' && to_find[find_i] == '\0')
			{
				return (str_array[str_i]);
			}
		}
		str_i++;
		find_i = 0;
		index = 0;
	}
	return (0);
}

void	ft_puterror(char *err)
{
	while (*err != 0)
		write(2, err++, 1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_error(argc, argv[1])))
			return (0);
		ft_engine("numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		if (!(ft_error(argc, argv[2])))
			return (0);
		ft_engine(argv[1], argv[2]);
	}
	if (argc != 2 && argc != 3)
	{
		ft_puterror("Error\n");
		return (0);
	}
}
