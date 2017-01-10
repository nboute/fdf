/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:51:15 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 17:51:04 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int pow)
{
	if (pow == 0)
		return (1);
	return (nb * ft_recursive_power(nb, pow - 1));
}

char		*ft_itoa(int n)
{
	char	*nb;
	short	exp;
	short	i;
	short	neg;
	long	nbr;

	nbr = (long)n;
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	exp = 0;
	while ((nbr / ft_recursive_power(10, exp)) >= 10)
		exp++;
	if ((nb = (char*)malloc(exp + 2 + neg)) == NULL)
		return (NULL);
	if (neg)
		nb[0] = '-';
	i = 0;
	while (i <= exp)
	{
		nb[i + neg] = ((nbr / ft_recursive_power(10, exp - i)) % 10) + '0';
		i++;
	}
	nb[i + neg] = '\0';
	return (nb);
}
