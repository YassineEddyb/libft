/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:19:07 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/04 15:24:53 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = malloc(count * size);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
