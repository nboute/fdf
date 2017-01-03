/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:29:41 by nboute            #+#    #+#             */
/*   Updated: 2017/01/03 20:51:19 by nboute           ###   ########.fr       */
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
		return (WHITE);
	else
		return (YELLOW);
}

void		ft_setmap(t_honk *honk)
{
	int	y;
	int	x;

	y = 0;
	while (y < honk->ghei)
	{
		x = 0;
		while (x < honk->gwid)
		{
			honk->grid[y][x].x = honk->grid[y][x]._x * honk->zoom;
			honk->grid[y][x].y = honk->grid[y][x]._y * honk->zoom;
			honk->grid[y][x].z = honk->grid[y][x]._z * honk->zoom;
			x++;
		}
		y++;
	}
}

void		ft_rotate_x(t_honk *honk, float angle)
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

void		ft_rotate_y(t_honk *honk, float angle)
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

void		ft_rotate_z(t_honk *honk, float angle)
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

void		ft_rotate_axis(t_point *p, float x, float y, float z)
{
	double	tmp;

	if (x)
	{
		tmp = (cos(x) * p->y) - (sin(x) * p->z);
		p->z = (sin(x) * p->y) + (cos(x) * p->z);
		p->y = tmp;
	}
	if (y)
	{
		tmp = (cos(y) * p->x) + (sin(y) * p->z);
		p->z = (cos(y) * p->z) - (sin(y) * p->x);
		p->x = tmp;
	}
	if (z)
	{
		tmp = (cos(z) * p->x) - (sin(z) * p->y);
		p->y = (sin(z) * p->x) + (cos(z) * p->y);
		p->x = tmp;
	}
}

void		ft_rotate(t_honk *honk)
{
	int		i;
	int		j;
	float	tmp;
	t_point	**g;

	g = honk->grid;
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			ft_rotate_axis(honk->grid[i] + j, honk->xang, honk->yang,
					honk->zang);
			j++;
		}
		i++;
	}
}

void		ft_place_point(t_honk *honk, double y, double x, int color)
{
	int		xp;
	int		yp;
	t_crgb	*rgb;

	xp = (honk->bpx / 8) * (x + honk->prex);
	yp = (y + honk->prey) * honk->size;
	if (xp >= 0 && xp < (honk->width * honk->bpx / 8) && yp >= 0
			&& yp < (honk->width * honk->size))
		*(unsigned *)(honk->data + yp + xp) = color;
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

int			ft_prepdraw(long *l0, long *l1, int *d, int *s)
{
	d[0] = labs(l1[0] - l0[0]);
	s[0] = l0[0] < l1[0] ? 1 : -1;
	d[1] = labs(l1[1] - l0[1]);
	s[1] = l0[1] < l1[1] ? 1 : -1;
	return (d[0] > d[1] ? d[0] / 2 : -d[1] / 2);
}

void		ft_getpoints(t_point *p0, t_point *p1, long *l0, long *l1)
{
	l0[0] = (long)p0->x;
	l0[1] = (long)p0->y;
	l1[0] = (long)p1->x;
	l1[1] = (long)p1->y;
}

void		ft_drawseg(t_point *p0, t_point *p1, t_honk *honk, int color)
{
	long	l0[2];
	long	l1[2];
	int		d[2];
	int		s[2];
	int		e[2];

	ft_getpoints(p0, p1, &l0[0], &l1[0]);
	e[0] = ft_prepdraw(&l0[0], &l1[0], &d[0], &s[0]);
	while (1)
	{
		ft_place_point(honk, l0[1], l0[0], color);
		if (l0[0] == l1[0] && l1[1] == l0[1])
			return ;
		e[1] = e[0];
		if (e[1] > -d[0])
		{
			e[0] -= d[1];
			l0[0] += s[0];
		}
		if (e[1] < d[1])
		{
			e[0] += d[0];
			l0[1] += s[1];
		}
	}
}

void		ft_drawmap(t_honk *honk)
{
	int		i;
	int		j;
	int		color;

	j = 0;
	color = set_color(honk->color);
	while (j < honk->ghei)
	{
		i = 0;
		while (i < honk->gwid)
		{
			if (j + 1 < honk->ghei)
				ft_drawseg(&honk->grid[j][i], &honk->grid[j + 1][i], honk,
						color);
			if (i + 1 < honk->gwid)
				ft_drawseg(&honk->grid[j][i], &honk->grid[j][i + 1], honk,
						color);
			i++;
		}
		j++;
	}
}

void		ft_empty_grid(t_honk *honk)
{
	int	y;

	y = 0;
	while (y < honk->height)
		ft_bzero(honk->data + honk->size * y++, honk->width * honk->bpx / 8);
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
}

void		ft_draw(t_honk *honk)
{
	int	i;
	int	j;

	i = 0;
	ft_drawmap(honk);
	ft_drawcolors(honk);
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
}

int			ft_rotate_action(t_honk *honk)
{
	if (honk->xrot != 2 && (honk->xrot || honk->yrot || honk->zrot))
	{
		honk->xang += honk->xrot;
		honk->yang += honk->yrot;
		honk->zang += honk->zrot;
	}
	honk->xang = (honk->xang == 360 || honk->xang == 0) ? 0 : honk->xang;
	honk->yang = (honk->yang == 360 || honk->yang == 0) ? 0 : honk->yang;
	honk->zang = (honk->zang == 360 || honk->zang == 0) ? 0 : honk->zang;
	if (honk->xrot == 2)
	{
		honk->xang += (honk->xang >= 180) ? 1 : -1;
		honk->yang += (honk->yang >= 180) ? 1 : -1;
		honk->zang += (honk->zang >= 180) ? 1 : -1;
		if (honk->xang == 0 && honk->yang == 0 && honk->zang == 0)
			honk->xrot = 0;
	}
	ft_rotate(honk);
/*	if (honk->xang)
		ft_rotate_x(honk, (float)(M_PI * (float)honk->xang / (float)180));
	if (honk->yang)
		ft_rotate_y(honk, (float)(M_PI * (float)honk->yang / (float)180));
	if (honk->zang)
		ft_rotate_z(honk, (float)(M_PI * (float)honk->zang / (float)180));
*/	return (0);
}

int			ft_mouse_pressed(int button, int x, int y, t_honk *honk)
{
	if (x < 54 && y < 54)
		honk->color = (x / 18) * 3 + y / 18;
	return (0);
}

int			ft_redraw_map(t_honk *honk)
{
	if (honk->k)
		honk->color = (honk->color + 1) % 9;
	ft_empty_grid(honk);
	ft_setmap(honk);
	ft_rotate_action(honk);
	ft_draw(honk);
	return (0);
}

int			ft_key_pressed(int keycode, t_honk *honk)
{
	if (keycode == 6)
		honk->zrot = honk->zrot == 0 ? 1 : 0;
	if (keycode == 7)
		honk->xrot = honk->xrot == 0 ? 1 : 0;
	if (keycode == 12)
		honk->xrot = (honk->xrot == 2) ? 0 : 2;
	if (keycode == 16)
		honk->yrot = honk->yrot == 0 ? 1 : 0;
	if (keycode == 49)
		honk->k = honk->k == 0 ? 1 : 0;
	if (keycode == 69)
		honk->zoom += honk->zoom >= 5 ? 1 : 0.1;
	if (keycode == 78)
		honk->zoom -= honk->zoom < 5.1 ? 0.1 : 1;
	if (honk->zoom > 100)
		honk->zoom = 100;
	if (honk->zoom < 0.1)
		honk->zoom = 0.1;
	honk->zoom = roundf(honk->zoom * 10) / 10;
	printf("%f|%f|%f\n", honk->zang, honk->yang, honk->zang);
	return (0);
}

t_readlines	*ft_get_grid(int fd, t_honk *honk)
{
	char		*buff;
	t_readlines	*tmp;
	t_readlines	*start;

	honk->gwid = 0;
	honk->ghei = 1;
	get_next_line(fd, &buff);
	if (!(start = (t_readlines*)malloc(sizeof(t_readlines))))
		return (0);
	tmp = start;
	tmp->tab = ft_strsplit(buff, ' ');
	while (tmp->tab[honk->gwid])
		honk->gwid++;
	while (get_next_line(fd, &buff) > 0)
	{
		if (!(tmp->next = (t_readlines*)malloc(sizeof(t_readlines))))
			return (0);
		tmp = tmp->next;
		tmp->tab = ft_strsplit(buff, ' ');
		tmp->next = NULL;
		honk->ghei++;
	}
	return (start);
}

void		ft_sethonk_p2(t_honk *honk, t_readlines *start, t_readlines *tmp)
{
	int		i;
	int		n;

	honk->grid = (t_point**)malloc(sizeof(t_point*) * (honk->ghei));
	i = 0;
	tmp = start;
	while (tmp && (n = -1))
	{
		honk->grid[i] = (t_point*)malloc(sizeof(t_point) * (honk->gwid));
		while (tmp->tab[++n])
		{
			honk->grid[i][n].z = ft_getnbr(tmp->tab[n]);
			honk->grid[i][n]._z = honk->grid[i][n].z;
			honk->grid[i][n].y = (float)i - (float)honk->ghei / (float)2 + 0.5;
			honk->grid[i][n]._y = honk->grid[i][n].y;
			honk->grid[i][n].x = (float)n - (float)honk->gwid / (float)2 + 0.5;
			honk->grid[i][n]._x = honk->grid[i][n].x;
		}
		i++;
		start = tmp;
		tmp = tmp->next;
		if (start)
			free(start);
	}
	honk->grid[i] = NULL;
}

void		ft_sethonk(t_honk *honk, int fd)
{
	t_readlines *tmp;

	honk->xang = 0;
	honk->yang = 0;
	honk->zang = 0;
	honk->k = 0;
	honk->xrot = 0;
	honk->yrot = 0;
	honk->zrot = 0;
	honk->color = (int)0x00FFFFFF;
	honk->prex = 500;
	honk->prey = 500;
	honk->width = 1000;
	honk->height = 1000;
	honk->zoom = 0.1;
	honk->mlx = mlx_init();
	honk->win = mlx_new_window(honk->mlx, honk->width, honk->height, "nboute");
	honk->img = mlx_new_image(honk->mlx, honk->width, honk->height);
	honk->data = mlx_get_data_addr(honk->img, &honk->bpx, &honk->size,
			&honk->endian);
	tmp = ft_get_grid(fd, honk);
	ft_sethonk_p2(honk, tmp, tmp);
}

int			main(int ac, char **av)
{
	t_honk	honk;
	int		fd;

	if (ac != 2)
		return (0);
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	ft_sethonk(&honk, fd);
	mlx_mouse_hook(honk.win, &ft_mouse_pressed, (void*)&honk);
	mlx_key_hook(honk.win, &ft_key_pressed, (void*)&honk);
	mlx_loop_hook(honk.mlx, &ft_redraw_map, &honk);
	mlx_loop(honk.mlx);
}
