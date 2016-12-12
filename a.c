/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:29:41 by nboute            #+#    #+#             */
/*   Updated: 2016/12/12 21:49:32 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "a.h"
#include "test.h"
#include <math.h>
#include <malloc/malloc.h>

void	ft_place_point(t_honk *honk, int y, int x, int color)
{
	int	_x;
	int	_y;

	_x = (honk->bpx / 8) * (x + honk->prex);
	_y = (y + honk->prey) * honk->size;
//	if ((y + honk->prey) * honk->size > 0 &&
	*(unsigned *)(honk->data + _y + _x ) = color;
}

t_point	*iso(t_point	*p, int x, int y)
{
	int	focaldist;

	focaldist = 1;
	p->_x = cos(M_PI / 6) * focaldist * (y - x);
	p->_y = sin(M_PI / 6) * focaldist * (x + y + (-2 * p->z));
//	p->_x = 0.82 * (double)x + p->z;
//	p->_y = 0.82 * (double)y + p->z;
	return (p);
}
/*
void	ft_drawseg(int x0, int y0, int x1, int y1, t_honk *honk)
{
	long	dx, dy, p;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);

	p = 2 * dy - dx;
	while (x0 <= x1)
	{
		ft_putchar('a');
		if (p <= 0)
		{
			x0++;
//			x0 = (x0 < x1) ? x0 + 1 : x0 - 1;
			p = p + 2 * dy;
		}
		else
		{
			x0++;
			y0++;
//			x0 = (x0 < x1) ? x0 + 1 : x0 - 1;
//			y0 = (y0 < y1) ? y0 + 1 : y0 - 1;
			p = p + 2 * (dy - dx);
		}
	*(unsigned *)(honk->data + ((y0 + honk->prey) * honk->size) + ((honk->bpx / 8) * (x0 + honk->prex))) = (int)0x00FFFFFF;
	}
//	*(unsigned *)(honk->data + ((y0 + honk->prey) * honk->size) + ((honk->bpx / 8) * (x0 + honk->prex))) = (int)0x00FFFFFF;

}*/
void	ft_drawseg(long x0, long y0, long x1, long y1, t_honk *honk)
{
	int dx = labs(x1-x0),
		sx = x0<x1 ? 1 : -1;
	int dy = labs(y1-y0),
		sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2,
		e2;
	int	draw;
	draw = 0;

	while (1)
	{
//		printf("\n%ld || %ld\n", ((x0 + honk->pre) * honk->size) + ((honk->bpx / 8) * (y0 + honk->pre)), malloc_size(honk->data));;
//		printf("%ld | %ld || %ld | %ld || %i\n", x0, y0, x1, y1, honk->size);
//		if (*(unsigned *)(honk->data + ((y0 + honk->pre) * honk->size) + ((honk->bpx / 8) * (x0 + honk->pre))) == (int)0x00FFFFFF)
//			draw = draw == 0 ? 1 : 1;
//		if (!draw)
		ft_place_point(honk, y0, x0, (int)0x00FFFFFF);
//			*(unsigned *)(honk->data + ((y0) * honk->size) + ((honk->bpx / 8) * (x0 + honk->prex))) = (int)0x00FFFFFF;
//		if (draw)
//			*(unsigned *)(honk->data + ((y0 + honk->pre) * honk->size) + ((honk->bpx / 8) * (x0 + honk->pre))) = (int)BROWN;
		if (x0 == x1 && y1 == y0)
		{
			return ;
		}
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_drawmap(t_honk *honk)
{
	int		i;
	int		j;

	j = 0;
	while (j < honk->ghei)
	{
		i = 0;
		while (i < honk->gwid)
		{
			if (j + 1 < honk->ghei)
			{
				ft_drawseg(lround(honk->grid[j][i]._x * honk->zoom), lround(honk->grid[j][i]._y * honk->zoom), lround(honk->grid[j + 1][i]._x * honk->zoom), lround(honk->grid[j + 1][i]._y * honk->zoom), honk);
			}
			if (i + 1 < honk->gwid)
			{
				ft_drawseg(honk->grid[j][i]._x * honk->zoom, honk->grid[j][i]._y * honk->zoom, honk->grid[j][i + 1]._x * honk->zoom, honk->grid[j][i + 1]._y * honk->zoom, honk);
			}
			i++;
		}
		j++;
	}
}

void	ft_empty_grid(t_honk *honk)
{
	int	i;
	i = 0;
	while (i < honk->height)
	{
		ft_bzero(honk->data + honk->size * i++, honk->width * honk->bpx / 8);
	}
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
}

void	ft_draw(t_honk *honk)
{
	int	i;
	int	j;
	i = 0;
	honk->prex = 500 - honk->xrange * honk->zoom / 2;
	honk->prey = 500 - honk->yrange * honk->zoom / 2;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			iso(honk->grid[i] + j, i, j);
			if (honk->grid[i][j].z == 0)
				ft_place_point(honk, lround(honk->grid[i][j]._y * honk->zoom),
						lround(honk->grid[i][j]._x * honk->zoom), (int)GREEN);
			else
				ft_place_point(honk, lround(honk->grid[i][j]._y * honk->zoom),
						lround(honk->grid[i][j]._x * honk->zoom), (int)BLUE);
			j++;
		}
		i++;
	}
	ft_drawmap(honk);
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
}

int		ft_mouse_pressed(int button, int x, int y, t_honk *honk)
{
	ft_empty_grid(honk);
	if (honk->zoom < 1)
		honk->zoom += 0.1;
	else if (honk->zoom < 100)
		honk->zoom++;
	else
		honk->zoom = 0.1;
	ft_draw(honk);
	return (0);
}

int		ft_key_pressed(int keycode, t_honk *honk)
{
	ft_empty_grid(honk);
//	if (keycode == 0)
//		ft_rotateX(honk);
//	if (keycode == 0)
//		ft_rotateY(honk);
//	ft_draw(honk);
	return (0);
}

int	main(int ac, char **av)
{
	t_honk	honk;
	int		fd;
	char	*buff;
	int		i;
	int		j;
	int		n;
	int		m;
	int		x;
	int		y;
	int		xmin = 0;
	int		xmax = 0;
	int		ymin = 0;
	int		ymax = 0;
	char	**tab;

	if (ac != 2)
		return (0);
	m = 0;
	n = 0;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &buff);
	tab = ft_strsplit(buff, ' ');
	while (tab[n])
		n++;
	honk.gwid = n;
	m++;
	while (get_next_line(fd, &buff) > 0)
		m++;
	honk.ghei = m;
	honk.grid = (t_point**)malloc(sizeof(t_point*) * (honk.ghei + 1));
	close(fd);
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &buff) > 0)
	{
		honk.grid[i] = (t_point*)malloc(sizeof(t_point) * (honk.gwid));
		tab = ft_strsplit(buff, ' ');
		n = 0;
		while (tab[n])
		{
			honk.grid[i][n].z = ft_getnbr(tab[n]);
			iso(honk.grid[i] + n, i, n);
			if (xmin > honk.grid[i][n]._x || !xmin)
				xmin = honk.grid[i][n]._x;
			if (ymin > honk.grid[i][n]._y || !ymin)
				ymin = honk.grid[i][n]._y;
			if (xmax < honk.grid[i][n]._x || !xmax)
				xmax = honk.grid[i][n]._x;
			if (ymax < honk.grid[i][n]._y || !ymax)
				ymax = honk.grid[i][n]._y;
			printf("%i ", honk.grid[i][n].z);
			n++;
		}
		printf("\n");
		i++;
	}
	honk.xrange = labs(xmin + xmax);
	printf("%d || %d || %d\n", honk.xrange, xmin, xmax);
	honk.yrange = labs(ymin + ymax);
	printf("%d || %d || %d\n", honk.yrange, ymin, ymax);
	honk.grid[i] = NULL;
	honk.width = 1000;
	honk.height = 1000;
	honk.zoom = 0.1;
	printf("%i\n", honk.prey);
	honk.mlx = mlx_init();
	honk.win = mlx_new_window(honk.mlx, honk.width, honk.height, "mlx tests");
	honk.img = mlx_new_image(honk.mlx, honk.width, honk.height);
	honk.data = mlx_get_data_addr(honk.img, &honk.bpx, &honk.size, &honk.endian);
	i = 0;
	ft_draw(&honk);
//		ft_drawmap(&honk);
		mlx_put_image_to_window(honk.mlx, honk.win, honk.img, 0, 0);
		mlx_mouse_hook(honk.win, &ft_mouse_pressed, (void*)&honk);
		mlx_key_hook(honk.win, &ft_key_pressed, (void*)&honk);
		mlx_loop(honk.mlx);
}
