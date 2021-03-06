/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:38:55 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/05 15:30:31 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (ft_strlen(s) < start || len == 0)
		return (ft_calloc(1, sizeof(char)));
	substr = ft_calloc(ft_strlen(s) - start, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	return (substr);
}

/*int main () {
	printf("%s", ft_substr("tripouille", 1, 1));
}*/
