/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:12:28 by nboute            #+#    #+#             */
/*   Updated: 2017/01/19 18:24:37 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_readlines	*ft_get_grid(int fd, t_honk *honk)
{
	char		*buff;
	t_readlines	*tmp;
	t_readlines	*start;

	if (get_next_line(fd, &buff) <= 0)
		ft_error();
	start = (t_readlines*)ft_memalloc(sizeof(t_readlines));
	tmp = start;
	honk->ghei++;
	tmp->tab = ft_strsplit(buff, ' ');
	free(buff);
	while (tmp->tab[honk->gwid])
		honk->gwid++;
	while (get_next_line(fd, &buff) > 0 && (honk->ghei++))
	{
		if (!(tmp->next = (t_readlines*)malloc(sizeof(t_readlines))))
			return (0);
		tmp = tmp->next;
		tmp->tab = ft_strsplit(buff, ' ');
		if ((int)ft_tablen(tmp->tab) != honk->gwid)
			ft_error();
		tmp->next = NULL;
		free(buff);
	}
	return (start);
}

void		ft_set_height(t_honk *honk, t_point *p, char *nb)
{
	p->z = ft_getnbr_int(nb);
	p->zs = p->z;
	if (p->z > honk->zmax)
		honk->zmax = p->z;
	if (p->z < honk->zmin)
		honk->zmin = p->z;
}

void		ft_sethonk_p2(t_honk *honk, t_readlines *start, t_readlines *tmp)
{
	int		i;
	int		n;

	honk->grid = (t_point**)malloc(sizeof(t_point*) * (honk->ghei + 1));
	i = 0;
	while (tmp && (n = -1) && i < honk->ghei)
	{
		honk->grid[i] = (t_point*)malloc(sizeof(t_point) * (honk->gwid));
		while (tmp->tab[++n])
		{
			ft_set_height(honk, honk->grid[i] + n, tmp->tab[n]);
			honk->grid[i][n].y = (float)i - (float)honk->ghei / (float)2 + 0.5;
			honk->grid[i][n].ys = honk->grid[i][n].y;
			honk->grid[i][n].x = (float)n - (float)honk->gwid / (float)2 + 0.5;
			honk->grid[i][n].xs = honk->grid[i][n].x;
		}
		i++;
		start = tmp;
		tmp = tmp->next;
		ft_clear_readline(start);
	}
	ft_clear_readline(tmp);
	honk->grad = 0;
	honk->grid[i] = NULL;
}

void		ft_setscale(t_honk *honk)
{
	int		i;
	int		j;
	int		range;
	int		range2;

	range = honk->zmax - honk->zmin;
	range2 = (honk->ghei + honk->gwid) > 16 ?
		(honk->ghei + honk->gwid) / 12 : (honk->ghei + honk->gwid) / 4;
	i = -1;
	while (++i < honk->ghei)
	{
		j = -1;
		while (++j < honk->gwid)
		{
			honk->grid[i][j].z = ft_map(honk->grid[i][j].z - honk->zmin, range,
					-range2, range2);
			honk->grid[i][j].zs = honk->grid[i][j].z;
			honk->grid[i][j].right = (j + 1) == honk->gwid ? NULL :
				&honk->grid[i][j + 1];
			honk->grid[i][j].down = (i + 1) < honk->ghei ?
				honk->grid[i + 1] + j : NULL;
		}
	}
	honk->zmin = -range2;
	honk->zmax = range2;
}

void		ft_sethonk(t_honk *honk, int fd)
{
	t_readlines *tmp;

	honk->gwid = 0;
	honk->ghei = 0;
	honk->color = 0;
	honk->xang = 0;
	honk->yang = 0;
	honk->zang = 0;
	honk->xrot = 0;
	honk->yrot = 0;
	honk->zrot = 0;
	honk->zmin = 0;
	honk->rs = 0.01;
	honk->zmax = 0;
	honk->width = 1000;
	honk->height = 1000;
	honk->mlx = mlx_init();
	tmp = ft_get_grid(fd, honk);
	honk->win = mlx_new_window(honk->mlx, honk->width, honk->height, "nboute");
	honk->img = mlx_new_image(honk->mlx, honk->width, honk->height);
	honk->data = mlx_get_data_addr(honk->img, &honk->bpx, &honk->size,
			&honk->endian);
	ft_sethonk_p2(honk, tmp, tmp);
	honk->zoom = ((float)500 / honk->ghei + (float)500 / honk->gwid) / 2;
}
