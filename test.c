/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:40:42 by nboute            #+#    #+#             */
/*   Updated: 2016/12/07 21:59:46 by nboute           ###   ########.fr       */
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

void line(int x0, int y0, int x1, int y1, char **tab)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;){
		tab[y0][x0] = '1';
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

int		main(int ac, char **av)
{
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
	while (tab[i])
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
	line(1, 3, 16, 5, tab);
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}
