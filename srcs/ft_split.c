/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:29:20 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/03 14:29:24 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

int	count_strs(char *str, char *sep)
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

int	*count_size(char *str, char *sep)
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

void	ft_strncpy(char *src, char *dest, int size)
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		index;
	int		*word;
	char	**words;

	words = (char **) malloc(sizeof(char *) * (count_strs(str, charset) + 1));
	word = count_size(str, charset);
	i = 0;
	index = 0;
	while (str[i])
	{
		if ((i == 0 && is_sep(str[i], charset) == 0) || \
			(is_sep(str[i], charset) == 0 && is_sep(str[i - 1], charset) == 1))
		{
			words[index] = malloc(sizeof(char) * (word[index] + 1));
			ft_strncpy(str + i, words[index], word[index]);
			index++;
		}
		i++;
	}
	words[index] = 0;
	return (words);
}
