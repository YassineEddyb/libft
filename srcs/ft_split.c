/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:29:20 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/06 16:05:22 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

static int	count_strs(const char *str, char sep)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (i == 0 && !is_sep(str[i], sep))
			counter++;
		else if (i > 0 && !is_sep(str[i], sep) && is_sep((str[i - 1]), sep))
			counter++;
		i++;
	}
	return (counter);
}

static int	*count_size(const char *str, char sep)
{
	int	i;
	int	index;
	int	*arr;
	int	size;

	size = count_strs(str, sep);
	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep))
			arr[index]++;
		else if (i > 0 && is_sep(str[i], sep) && !is_sep(str[i - 1], sep))
			index++;
		i++;
	}
	return (arr);
}

void	ft_strncpy(const char *src, char *dest, int size)
{
	int	i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	int		*word;
	char	**words;

	words = (char **) malloc(sizeof(char *) * (count_strs(s, c) + 1));
	word = count_size(s, c);
	i = 0;
	index = 0;
	while (s[i])
	{
		if ((i == 0 && is_sep(s[i], c) == 0) || \
			(is_sep(s[i], c) == 0 && is_sep(s[i - 1], c) == 1))
		{
			words[index] = malloc(sizeof(char) * (word[index] + 1));
			ft_strncpy((char *)s + i, words[index], word[index]);
			index++;
		}
		i++;
	}
	words[index] = 0;
	free(word);
	return (words);
}
