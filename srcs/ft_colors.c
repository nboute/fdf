/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:04 by nboute            #+#    #+#             */
/*   Updated: 2017/01/19 14:47:13 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			ft_gradation(unsigned int col, unsigned int col2, int p)
{
	int	r;
	int	g;
	int	b;

	r = ((col2 >> 16) & 0x000000FF) - ((col >> 16) & 0x000000FF);
	g = ((col2 >> 8) & 0x000000FF) - ((col >> 8) & 0x000000FF);
	b = (col2 & 0x000000FF) - (col & 0x000000FF);
	r = (r * p) / 100;
	g = (g * p) / 100;
	b = (b * p) / 100;
	return (col + r * 65536 + g * 256 + b);
}

void		ft_set_gradations(t_honk *honk)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	color = set_color(honk->color);
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			if (honk->grid[i][j].zs == 0)
				honk->grid[i][j].color = color;
			else if (honk->grid[i][j].zs < 0)
				honk->grid[i][j].color = ft_gradation(BLACK, color,
						ft_map(honk->grid[i][j].zs - honk->zmin,
							honk->zmax - honk->zmin, 25, 100));
			else
				honk->grid[i][j].color = ft_gradation(color, WHITE,
						ft_map(honk->grid[i][j].zs - honk->zmin,
							honk->zmax - honk->zmin, 0, 80));
			j++;
		}
		i++;
	}
}

int			set_color(int cp)
{
	if (cp == 0)
		return (BLUE);
	else if (cp == 1)
		return (BROWN);
	else if (cp == 2)
		return (GREEN);
	else if (cp == 3)
		return (PINK);
	else if (cp == 4)
		return (RED);
	else if (cp == 5)
		return (TURQUOISE);
	else if (cp == 6)
		return (VIOLET);
	else if (cp == 7)
		return (ORANGE);
	else
		return (YELLOW);
}

void		ft_drawcolors(t_honk *honk)
{
	int	i;
	int	j;

	i = 0;
	while (i < 54)
	{
		j = 0;
		while (j < 54)
		{
			ft_place_point(honk, i - 500, j - 500,
					set_color((j / 18) * 3 + (i / 18)));
			j++;
		}
		i++;
	}
}

void		ft_clear_readline(t_readlines *elem)
{
	if (elem)
	{
		if (elem->tab)
			ft_tabdel(elem->tab);
		elem->tab = NULL;
		free(elem);
		elem = NULL;
	}
}
