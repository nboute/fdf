/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:20:07 by nboute            #+#    #+#             */
/*   Updated: 2016/12/08 17:29:52 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "a.h"
#include "test.h"
#include <math.h>

t_point	**ft_get_grid(int fd, int height)
{
	t_point		**grid;
	int			i;
	int			j;
	char		*str;
	char		**tab;

	j = 0;
	grid = (t_point**)malloc(sizeof(t_point*) * height);
	while (get_next_line(fd, &str))
	{
		i = 0;
		tab = ft_strsplit(str, ' ');
		while (tab[i])
			i++;
		grid[j] = (t_point*)malloc(sizeof(t_point) * i);
		i = 0;
		while (tab[i])
		{
			grid[j][i].z = ft_getnbr(tab[i]);
			i++;
		}
		ft_tabdel(tab);
		j++;
	}
	return (grid);
}

t_point		**ft_read_fdf(char *fn)
{
	int			fd;
	int			i;
	char		*str;

	if ((fd = open(fn, O_RDONLY) <= 0))
		return (0);
	i = 0;
	while (get_next_line(fd, &str))
		i++;
	close(fd);
	if ((fd = open(fn, O_RDONLY) <= 0))
		return (0);
	return (ft_get_grid(fd, i));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ft_read_fdf(av[1]);
}
