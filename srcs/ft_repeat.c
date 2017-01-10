/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:08:50 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 16:52:38 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
			honk->grid[y][x].x = honk->grid[y][x].xs * honk->zoom;
			honk->grid[y][x].y = honk->grid[y][x].ys * honk->zoom;
			honk->grid[y][x].z = honk->grid[y][x].zs * honk->zoom;
			x++;
		}
		y++;
	}
}

void		ft_place_point(t_honk *honk, double y, double x, int color)
{
	int		xp;
	int		yp;

	xp = (honk->bpx / 8) * (x + honk->prex);
	yp = (y + honk->prey) * honk->size;
	if (xp >= 0 && xp < (honk->width * honk->bpx / 8) && yp >= 0
			&& yp < (honk->width * honk->size))
		if (!*(honk->data + yp + xp))
			*(unsigned *)(honk->data + yp + xp) = color;
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
	if (honk->grad)
	{
		ft_sort_grid(honk);
		ft_drawmap(honk, &ft_drawseg_grad);
	}
	else
		ft_drawmap(honk, &ft_drawseg);
	ft_drawcolors(honk);
	mlx_put_image_to_window(honk->mlx, honk->win, honk->img, 0, 0);
}

int			ft_redraw_map(t_honk *honk)
{
	ft_empty_grid(honk);
	ft_setmap(honk);
	ft_rotate_action(honk);
	ft_draw(honk);
	return (0);
}
