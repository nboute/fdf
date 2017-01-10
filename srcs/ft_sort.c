/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:14:32 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 19:18:21 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		*ft_get_vals(t_honk *honk)
{
	int	*vals;
	int	i;
	int	j;
	int	val;

	vals = (int*)malloc(sizeof(int) * honk->ghei);
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		val = 0;
		while (j < honk->gwid)
			val += honk->grid[i][j++].zs;
		vals[i++] = val;
	}
	return (vals);
}

void	ft_sort_grid(t_honk *honk)
{
	int		i;
	int		ordered;
	int		*vals;
	int		tmp;

	ordered = 0;
	vals = ft_get_vals(honk);
	while (!ordered && (i = -1))
	{
		ordered = 1;
		while (++i + 1 < honk->ghei)
		{
			if (vals[i] < vals[i + 1])
			{
				ordered = 0;
				tmp = vals[i];
				vals[i] = vals[i + 1];
				vals[i + 1] = tmp;
				ft_memswap((void**)honk->grid + i, (void**)honk->grid + i + 1);
			}
		}
	}
	free(vals);
}

void	ft_sort_grid_rev(t_honk *honk)
{
	int		i;
	int		ordered;
	int		*vals;
	int		tmp;
	t_point	*p;

	ordered = 0;
	vals = ft_get_vals(honk);
	while (!ordered && (i = -1))
	{
		ordered = 1;
		while (++i + 1 < honk->ghei)
		{
			if (vals[i] > vals[i + 1])
			{
				ordered = 0;
				tmp = vals[i];
				vals[i] = vals[i + 1];
				vals[i + 1] = tmp;
				p = honk->grid[i];
				honk->grid[i] = honk->grid[i + 1];
				honk->grid[i + 1] = p;
			}
		}
	}
}

void	ft_error(void)
{
	ft_putstr("Invalid file\n");
	exit(-1);
}

int		ft_getnbr_int(char *str)
{
	long	nb;
	int		i;
	int		sign;
	int		digits;

	i = 0;
	digits = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && digits < 12)
	{
		nb = (nb * 10) + (str[i++] - '0');
		digits++;
	}
	nb = nb * sign;
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error();
	return ((int)nb);
}
