/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:02:47 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 16:48:27 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		ft_rotate_axis(t_point *p, float x, float y, float z)
{
	float	tmp;

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
	t_point	**g;
	float	ang[3];

	ang[0] = (honk->xang * M_PI) / 180;
	ang[1] = (honk->yang * M_PI) / 180;
	ang[2] = (honk->zang * M_PI) / 180;
	g = honk->grid;
	i = 0;
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			ft_rotate_axis(honk->grid[i] + j, ang[0], ang[1], ang[2]);
			j++;
		}
		i++;
	}
}

void		ft_keep_angles(float *ang, int rot, float sp)
{
	*ang += (float)rot * sp;
	while (*ang < 0)
		*ang += 360;
	while (*ang >= 360)
		*ang -= 360;
}

int			ft_rotate_action(t_honk *honk)
{
	float	n;

	if (honk->xrot && honk->xrot != 2)
		ft_keep_angles(&honk->xang, honk->xrot, honk->rs);
	if (honk->yrot)
		ft_keep_angles(&honk->yang, honk->yrot, honk->rs);
	if (honk->zrot)
		ft_keep_angles(&honk->zang, honk->zrot, honk->rs);
	if (honk->xrot == 2)
	{
		n = (float)1 / honk->rs;
		honk->xang = roundf(honk->xang * n) / n;
		honk->yang = roundf(honk->yang * n) / n;
		honk->zang = roundf(honk->zang * n) / n;
		if (honk->xang > 0 && honk->xang < 360)
			ft_keep_angles(&honk->xang, (honk->xang >= 180) ? 1 : -1, honk->rs);
		if (honk->yang > 0 && honk->yang < 360)
			ft_keep_angles(&honk->yang, (honk->yang >= 180) ? 1 : -1, honk->rs);
		if (honk->zang > 0 && honk->zang < 360)
			ft_keep_angles(&honk->zang, (honk->zang >= 180) ? 1 : -1, honk->rs);
		if (honk->xang == 0 && honk->yang == 0 && honk->zang == 0)
			honk->xrot = 0;
	}
	ft_rotate(honk);
	return (0);
}
