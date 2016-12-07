/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:40:42 by nboute            #+#    #+#             */
/*   Updated: 2016/12/06 22:13:33 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "test.h"

void	ft_drawseg(int x1, int y1, int x2, int y2, char	**tab, char c)
{
	int	dx;
	int	dy;
	int e;

	e = 0;
	dx = x2 - x1;
	dy = y2 - y1;
//	if (x1 < x2)
//	{
		while (x1 <= x2 && tab[y1][x1])
		{
			tab[y1][x1] = c;
			e += dy;
			if ((e << 1) >= dx)
			{
				y1++;
				e -= dx;
			}
			x1++;
		}
//	}
/*	else
	{
		while (y1 <= y2 && tab[y1])
		{
			tab[y1][x1] = c;
			e += dx;
			if ((e << 1) >= dy)
			{
				x1++;
				e-= dy;
			}
			y1++;
		}
	}*/
}

t_point	*iso(t_point	*p)
{
	p->_x = (sqrt(2) / 2 * (double)p->x / (double)p->y);
	p->_y = (sqrt((double)2 / (double)3) - ((double)1 / sqrt(6))
			* (p->x + p->y));
	return (p);
}

int		main(int ac, char **av)
{
	t_point	point;
	iso(&point);
	/*
	char	*str;
	int		fd;
	char	**tab;
	int		ret;
	int		i;
	int		j;
	int		n;

	fd = open(av[1], O_RDONLY);
	str = (char*)malloc(5000);
	ret = read(fd, str, 5000);
	str[ret] = '\0';
	tab = ft_strsplit(str, '\n');
	i = 0;
	while (i < 11)
	{
		j = 0;
		n = 0;
		while (tab[i][j] != 0)
		{
			while (tab[i][j] && !ft_isdigit(tab[i][j]))
				j++;
			if (tab[i][j])
				tab[i][n++] = (ft_getnbr(tab[i] + j)) + '0';
			while (tab[i][j] && ft_isdigit(tab[i][j]))
				j++;
		}
		tab[i][n] = '\0';
		i++;
	}
	ft_drawseg(1, 3, 16, 5, tab, '1');
	i = 0;
	while (i < 11)
		printf("%s\n", tab[i++]);
		*/
}
