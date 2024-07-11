/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrochd <rrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:40:10 by rrochd            #+#    #+#             */
/*   Updated: 2024/07/02 16:40:36 by rrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
				&& c <= '9')))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		in_word;
	char	*start;
	int		diff;

	in_word = 0;
	start = str;
	diff = 'a' - 'A';
	while (*str)
	{
		if (ft_str_is_alpha(*str))
		{
			if (!in_word && (*str >= 'a' && *str <= 'z'))
				*str -= diff;
			else if (in_word && (*str >= 'A' && *str <= 'Z'))
				*str += diff;
			in_word = 1;
		}
		else
			in_word = 0;
		str++;
	}
	return (start);
}
