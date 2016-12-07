/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:29:41 by nboute            #+#    #+#             */
/*   Updated: 2016/12/07 21:52:48 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "a.h"
#include "test.h"
#include <math.h>

t_point	*iso(t_point	*p, int x, int y)
{
	p->_x = 0.82 * (double)x + p->z;
	p->_y = 0.82 * (double)y + p->z;
	return (p);
}

void	ft_drawseg(double x0, double y0, double x1, double y1, t_honk *honk)
{
	int dx = fabs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = fabs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	while (1)
	{
 *(unsigned *)(honk->data + ((lround(x1) + 500) * honk->size + (honk->bpx / 8) * (lround(y1) + 500))) = (int)0x00FF0000;
		if (x0==x1 && y0==y1)
			break;
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
/*{
  int	dx;
  int	dy;
  int e;

  e = 0;
  dx = x2 - x1;
  dy = y2 - y1;
  if (x1 < x2)
  {
  while (x1 <= x2 && (honk->data + y1 * honk->size + x1 * honk->bpx / 8))
  {
 *(unsigned *)(honk->data + (x1 + 50) * honk->size + (honk->bpx / 8) * (y1 + 50)) = (int)0x00FF0000;
 e += dy;
 if ((e << 1) >= dx)
 {
 y1++;
 e -= dx;
 }
 x1++;
 }
 }
 else
 {
 while (y1 <= y2 && (honk->data + y1 * honk->size + x1 * honk->bpx / 8))
 {
 *(unsigned *)(honk->data + (x1 + 50) * honk->size + (honk->bpx / 8) * (y1 + 50)) = (int)0x00FF0000;
 e += dx;
 if ((e << 1) >= dy)
 {
 x1++;
 e-= dy;
 }
 y1++;
 }
 }
 }

 void	ft_drawseg(int x1, int y1, int x2, int y2, t_honk *honk)
 {
 int	dx;
 int	dy;
 float e;
 e = x2 / 100 - x1 / 100;
 dy = e * 2;
 dx = (y2 - y1) * 2;
 ft_putnbr(dx);
 ft_putchar('|');
 ft_putnbr(dy);
 ft_putchar('\n');
 while (x1 < x2)
 {
 *(unsigned *)(honk->data + (x1 + 50) * honk->size + (honk->bpx / 8) * (y1 + 50)) = (int)0x00FF0000;
 if ((e = e - dy) >= 0)
 {
 y1++;
 e += dx;
 }
 x1++;
 }
 }
 */
void	ft_drawmap(t_honk *honk)
{
	int		i;
	int		j;

	i = 0;
	while (i < honk->gwid)
	{
		j = 0;
		while (j < honk->ghei)
		{
			if (j + 1 != honk->gwid)
			{
				ft_drawseg(honk->grid[i][j]._x * ZO, honk->grid[i][j]._x * ZO, honk->grid[i][j + 1]._x * ZO, honk->grid[i][j]._y * ZO, honk);
			}
			if (i + 1 != honk->ghei)
			{
				ft_drawseg(honk->grid[i][j]._x * ZO, honk->grid[i][j]._x * ZO, honk->grid[i + 1][j]._x * ZO, honk->grid[i + 1][j]._y * ZO, honk);
			}
			j++;
		}
		i++;
	}
}

int		ft_key_pressed(int keycode, t_honk *honk)
{
	int	i;
	int	j;
	i = 0;
	printf("%i\n", keycode);
	/*
	   while (i < 1000)
	   {
	   j = 0;
	   while (j < 1000)
	   {
	   if (*(unsigned *)(honk->data + i * honk->size + (honk->bpx / 8) * j) == GREEN)
	 *(unsigned *)(honk->data + i * honk->size + (honk->bpx / 8) * j) = BLUE;
	 else
	 *(unsigned *)(honk->data + i * honk->size + (honk->bpx / 8) * j) = BROWN;
	 j++;
	 }
	 i++;
	 }
	 */
	while (i < 1000)
	{
		ft_bzero(honk->data + i++ * honk->size, honk->bpx / 8 * 1000);
	}
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
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
			printf("%i ", honk.grid[i][n].z);
			n++;
		}
		printf("\n");
		i++;
	}
	honk.grid[i] = NULL;
	honk.width = 1000;
	honk.height = 1000;
	honk.mlx = mlx_init();
	honk.win = mlx_new_window(honk.mlx, 1000, 1000, "mlx tests");
	honk.img = mlx_new_image(honk.mlx, honk.width, honk.height);
	honk.data = mlx_get_data_addr(honk.img, &honk.bpx, &honk.size, &honk.endian);
	i = 0;
	while (i < honk.ghei)
	{
		j = 0;
		while (j < honk.gwid)
		{	
			if (honk.grid[i][j].z == 0)
			{
				iso(honk.grid[i] + j, i, j);
				*(unsigned *)(honk.data + (lround(((honk.grid[i][j]._y * ZO + 500))) * honk.size) + ((honk.bpx / 8) * lround((honk.grid[i][j]._x * ZO + 500)))) = (int)GREEN;
				/*				*(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)BLUE;
				 *(unsigned *)(honk.data + (i * 100 + 50) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)BLUE;
				 */			}
				j++;
		}
		i++;
	}
	i = 0;
	while (i < honk.ghei)
	{
		j = 0;
		while (j < honk.gwid)
		{
			if (honk.grid[i][j].z)
			{
				iso(honk.grid[i] + j, i, j);
				*(unsigned *)(honk.data + (lround(((honk.grid[i][j]._y * ZO + 500))) * honk.size) + ((honk.bpx / 8) * lround((honk.grid[i][j]._x * ZO + 500)))) = (int)BLUE;
				/*				*(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50 + 1) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50 - 1) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50) * honk.size + (honk.bpx / 8) * (1 + j * 100 + 50)) = (int)GREEN;
				 *(unsigned *)(honk.data + (i * 100 + 50) * honk.size + (honk.bpx / 8) * (-1 + j * 100 + 50)) = (int)GREEN;
				 */			}
				j++;
		}
		i++;
	}
	ft_drawmap(&honk);
	mlx_put_image_to_window(honk.mlx, honk.win, honk.img, 0, 0);
	//	mlx_key_hook(honk.win, &ft_key_pressed, (void*)&honk);
	mlx_loop(honk.mlx);
}
