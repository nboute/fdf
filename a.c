/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:29:41 by nboute            #+#    #+#             */
/*   Updated: 2016/12/16 22:58:00 by nboute           ###   ########.fr       */
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

void	ft_setmap(t_honk *honk)
{
	int	y;
	int	x;

	y = 0;
	while (y < honk->ghei)
	{
		x = 0;
		while (x < honk->gwid)
		{
			honk->grid[y][x].x = honk->grid[y][x]._x;
			honk->grid[y][x].y = honk->grid[y][x]._y;
			honk->grid[y][x].z = honk->grid[y][x]._z;
			x++;
		}
		y++;
	}
}

void	ft_set_colors(t_honk *honk, int min, int max)
{
	int	range;
	t_point	**g;
	int	val;

	g = honk->grid;
	range = max - min;
	int		i;
	int		j;
	j = 0;
	while (j < honk->ghei)
	{
		i = 0;
		while (i < honk->gwid)
		{
			val = 255 * (((float)g[j][i].z / (float)range));
			g[j][i].color = val * 0x000100;
			i++;
		}
		j++;
	}
}

void	ft_rotateX(t_honk *honk, float angle)
{
	int		i;
	int		j;
	t_point	**g;
	double	tmp;

	g = honk->grid;
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			tmp = (cos(angle) * g[i][j].y) - (sin(angle) * g[i][j].z);
			g[i][j].z = (sin(angle) * g[i][j].y) + (cos(angle) * g[i][j].z);
			g[i][j].y = tmp;
			j++;
		}
		i++;
	}
}

void	ft_rotateY(t_honk *honk, float angle)
{
	int		i;
	int		j;
	t_point	**g;
	double	tmp;

	g = honk->grid;
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			tmp = (cos(angle) * g[i][j].x) + (sin(angle) * g[i][j].z);
			g[i][j].z = (cos(angle) * g[i][j].z) - (sin(angle) * g[i][j].x);
			g[i][j].x = tmp;
			j++;
		}
		i++;
	}
}

void	ft_rotateZ(t_honk *honk, float angle)
{
	int		i;
	int		j;
	t_point	**g;
	double	tmp;

	g = honk->grid;
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			tmp = (cos(angle) * g[i][j].x) - (sin(angle) * g[i][j].y);
			g[i][j].y = (sin(angle) * g[i][j].x) + (cos(angle) * g[i][j].y);
			g[i][j].x = tmp;
			j++;
		}
		i++;
	}
}

void	ft_place_point(t_honk *honk, double y, double x, int color)
{
	int	_x;
	int	_y;

	_x = (honk->bpx / 8) * (x + honk->prex);
	_y = (y + honk->prey) * honk->size;
//	if ((y + honk->prey) * honk->size > 0 &&
	if (_x >= 0 && _x < (honk->width * honk->bpx / 8) && _y >= 0 && _y < (honk->width * honk->size))
	*(unsigned *)(honk->data + _y + _x ) = color;
}

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
		ft_place_point(honk, y0, x0, (int)0x00FFFFFF);
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
				ft_drawseg(lround(honk->grid[j][i].x * honk->zoom), lround(honk->grid[j][i].y * honk->zoom), lround(honk->grid[j + 1][i].x * honk->zoom), lround(honk->grid[j + 1][i].y * honk->zoom), honk);
			}
			if (i + 1 < honk->gwid)
			{
				ft_drawseg(honk->grid[j][i].x * honk->zoom, honk->grid[j][i].y * honk->zoom, honk->grid[j][i + 1].x * honk->zoom, honk->grid[j][i + 1].y * honk->zoom, honk);
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
//	honk->prex = 500 - honk->xrange * honk->zoom / 2;
//	honk->prey = 500 - honk->yrange * honk->zoom / 2;
//	while (i < honk->ghei)
//	{
//		j = 0;
//		while (j < honk->gwid)
//		{
//				ft_place_point(honk, honk->grid[i][j].y * honk->zoom,
//						honk->grid[i][j].x * honk->zoom, GREEN);
//			j++;
//		}
//		i++;
//	}
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
	printf("\n____________________________________\n");
	ft_empty_grid(honk);
	ft_setmap(honk);
	if (keycode == 7)
	{
		honk->xang = (honk->xang + 30) % 360;
		ft_rotateX(honk, (float)(M_PI * (float)honk->xang / (float)180));
		ft_rotateY(honk, (float)(M_PI * (float)honk->yang / (float)180));
		ft_rotateZ(honk, (float)(M_PI * (float)honk->zang / (float)180));
	}
	if (keycode == 16)
	{
		honk->yang = (honk->yang + 30) % 360;
		ft_rotateY(honk, (float)(M_PI * (float)honk->yang / (float)180));
		ft_rotateX(honk, (float)(M_PI * (float)honk->xang / (float)180));
		ft_rotateZ(honk, (float)(M_PI * (float)honk->zang / (float)180));
	}
	if (keycode == 6)
	{
		honk->zang = (honk->zang + 30) % 360;
		ft_rotateZ(honk, (float)(M_PI * (float)honk->zang / (float)180));
		ft_rotateX(honk, (float)(M_PI * (float)honk->xang / (float)180));
		ft_rotateY(honk, (float)(M_PI * (float)honk->yang / (float)180));
	}
		ft_draw(honk);
	printf("X %i | Y %i | Z %i\n", honk->xang, honk->yang, honk->zang);
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
	int		zmin = 0;
	int		zmax = 0;
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
			honk.grid[i][n]._z = ft_getnbr(tab[n]);
			honk.grid[i][n].y = (float)i - (float)honk.ghei / (float)2 + 0.5;
			honk.grid[i][n]._y = honk.grid[i][n].y;
			honk.grid[i][n].x = (float)n - (float)honk.gwid / (float)2 + 0.5;
			honk.grid[i][n]._x = honk.grid[i][n].x;
			if (zmin > honk.grid[i][n].z || !zmin)
				zmin = honk.grid[i][n].z;
			if (xmin > honk.grid[i][n].x || !xmin)
				xmin = honk.grid[i][n].x;
			if (ymin > honk.grid[i][n].y || !ymin)
				ymin = honk.grid[i][n].y;
			if (zmax < honk.grid[i][n].z || !zmax)
				zmax = honk.grid[i][n].z;
			if (xmax < honk.grid[i][n].x || !xmax)
				xmax = honk.grid[i][n].x;
			if (ymax < honk.grid[i][n].y || !ymax)
				ymax = honk.grid[i][n].y;
			printf("% 5.1lf", honk.grid[i][n].y);
			n++;
		}
		printf("\n");
		i++;
	}
	ft_set_colors(&honk, zmin, zmax);
	honk.xang = 0;
	honk.yang = 0;
	honk.zang = 0;
	honk.prex = 500;
	honk.prey = 500;
	printf("||%i|%i\n", honk.ghei, honk.gwid);
	honk.grid[i] = NULL;
	honk.width = 1000;
	honk.height = 1000;
	honk.zoom = 1;
	honk.mlx = mlx_init();
	honk.win = mlx_new_window(honk.mlx, honk.width, honk.height, "mlx tests");
	honk.img = mlx_new_image(honk.mlx, honk.width, honk.height);
	honk.data = mlx_get_data_addr(honk.img, &honk.bpx, &honk.size, &honk.endian);
	i = 0;
	ft_draw(&honk);
	mlx_put_image_to_window(honk.mlx, honk.win, honk.img, 0, 0);
	mlx_mouse_hook(honk.win, &ft_mouse_pressed, (void*)&honk);
	mlx_key_hook(honk.win, &ft_key_pressed, (void*)&honk);
	float o;
	o = 0;
	/*
	sleep(2);
	while (1)
	{
		ft_putchar('a');
		ft_empty_grid(&honk);
		ft_rotateX(&honk, (M_PI * (float)1) / (float)180);
		ft_draw(&honk);
		o = (o < 360) ? o + 1 : 0;
		sleep(1);
	}*/
		mlx_loop(honk.mlx);
}
