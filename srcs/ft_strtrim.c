/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:47 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/03 14:27:01 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_left(char const *str, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				count++;
			j++;
		}
		i++;
		if (count != i)
			return ((char *)str + count);
	}
	return (0);
}

int	trim_len(char *str, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(str) - 1;
	count = i;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				count--;
			j++;
		}
		i--;
		if (count != i)
			return (count + 1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	char	*temp;
	int		len;
	int		i;

	temp = trim_left(s1, set);
	if (!temp)
		return ((char *)s1);
	len = trim_len(temp, set);
	trimed_str = malloc(len + 1 * sizeof(char));
	i = 0;
	while (i < len)
	{
		trimed_str[i] = temp[i];
		i++;
	}
	trimed_str[i] = '\0';
	return (trimed_str);
}
