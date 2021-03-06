/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:58:02 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/06 15:57:29 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_to_str(long int nb, char *str, int len, int neg)
{
	int	i;

	i = 0;
	str[len] = '\0';
	if (nb == 0)
		str[0] = 48;
	while (nb >= 1)
	{
		str[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (neg == 1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int			count;
	long int	nb;
	long int	nbr;
	char		*str;
	int			neg;

	count = 1;
	nbr = n;
	nb = n;
	neg = 0;
	if (nb < 0)
	{
		count++;
		nbr *= -1;
		nb *= -1;
		neg = 1;
	}
	while (nb > 10)
	{
		count++;
		nb = nb / 10;
	}
	str = malloc((count + 1) * sizeof(char));
	nbr_to_str(nbr, str, count, neg);
	return (str);
}

/*int main () {
	printf("%s", ft_itoa(-2147483648));
}*/
