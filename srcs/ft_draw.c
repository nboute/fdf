/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:06:34 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 16:54:29 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			ft_prepdraw(long *l, int *d, int *s)
{
	d[0] = labs(l[2] - l[0]);
	s[0] = l[0] < l[2] ? 1 : -1;
	d[1] = labs(l[3] - l[1]);
	d[2] = 0;
	d[3] = d[0] + d[1];
	if (!d[3])
		d[3] = 1;
	s[1] = l[1] < l[3] ? 1 : -1;
	return (d[0] > d[1] ? d[0] / 2 : -d[1] / 2);
}

void		ft_getpoints(t_point *p0, t_point *p1, long *l)
{
	l[0] = (long)p0->x;
	l[1] = (long)p0->y;
	l[2] = (long)p1->x;
	l[3] = (long)p1->y;
}

void		ft_drawseg(t_point *p0, t_point *p1, t_honk *honk)
{
	long	l[4];
	int		d[4];
	int		s[2];
	int		e[2];

	ft_getpoints(p0, p1, &l[0]);
	e[0] = ft_prepdraw(&l[0], &d[0], &s[0]);
	while (1)
	{
		ft_place_point(honk, l[1], l[0], set_color(honk->color));
		if (l[0] == l[2] && l[3] == l[1])
			return ;
		e[1] = e[0];
		if (e[1] > -d[0])
			e[0] -= d[1];
		if (e[1] > -d[0])
			l[0] += s[0];
		if (e[1] < d[1])
			e[0] += d[0];
		if (e[1] < d[1])
			l[1] += s[1];
		d[2]++;
	}
}

void		ft_drawseg_grad(t_point *p0, t_point *p1, t_honk *honk)
{
	long	l[4];
	int		d[4];
	int		s[2];
	int		e[2];

	ft_getpoints(p0, p1, &l[0]);
	e[0] = ft_prepdraw(&l[0], &d[0], &s[0]);
	while (1)
	{
		ft_place_point(honk, l[1], l[0], ft_gradation(p0->color,
					p1->color, (d[2] * 100) / d[3]));
		if (l[0] == l[2] && l[3] == l[1])
			return ;
		e[1] = e[0];
		if (e[1] > -d[0])
			e[0] -= d[1];
		if (e[1] > -d[0])
			l[0] += s[0];
		if (e[1] < d[1])
			e[0] += d[0];
		if (e[1] < d[1])
			l[1] += s[1];
		d[2]++;
	}
}

void		ft_drawmap(t_honk *honk, void fct(t_point*, t_point*, t_honk*))
{
	int		i;
	int		j;
	int		color;

	i = 0;
	color = set_color(honk->color);
	while (i < honk->ghei)
	{
		j = 0;
		while (j < honk->gwid)
		{
			if (honk->grid[i][j].right)
				fct(&honk->grid[i][j], honk->grid[i][j].right, honk);
			if (honk->grid[i][j].down)
				fct(&honk->grid[i][j], honk->grid[i][j].down, honk);
			j++;
		}
		i++;
	}
}
