/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:50:05 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 17:45:22 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			ft_mouse_pressed(int button, int x, int y, t_honk *honk)
{
	button = button + 1 - 1;
	if (x < 54 && y < 54)
	{
		honk->color = (x / 18) * 3 + y / 18;
		ft_set_gradations(honk);
	}
	return (0);
}

void		ft_key_pressed_p3(int keycode, t_honk *honk)
{
	if (keycode == 126)
		honk->xrot = honk->xrot == 1 ? 0 : 1;
	if (keycode == 125)
		honk->xrot = honk->xrot == -1 ? 0 : -1;
	else if (keycode == 124)
		honk->yrot = honk->yrot == 1 ? 0 : 1;
	else if (keycode == 123)
		honk->yrot = honk->yrot == -1 ? 0 : -1;
	else if (keycode == 6)
		honk->zrot = honk->zrot == 1 ? 0 : 1;
	else if (keycode == 0)
		honk->zrot = honk->zrot == -1 ? 0 : -1;
	else if (keycode == 15)
	{
		honk->xang = 0;
		honk->yang = 0;
		honk->zang = 0;
	}
	if (keycode == 35 || keycode == 15)
	{
		honk->xrot = 0;
		honk->yrot = 0;
		honk->zrot = 0;
	}
}

void		ft_key_pressed_p2(int keycode, t_honk *honk)
{
	if (keycode == 82)
		honk->rs = 0.05;
	else if (keycode == 83)
		honk->rs = 0.1;
	else if (keycode == 84)
		honk->rs = 0.2;
	else if (keycode == 85)
		honk->rs = 0.5;
	else if (keycode == 86)
		honk->rs = 0.8;
	else if (keycode == 87)
		honk->rs = 1;
	else if (keycode == 88)
		honk->rs = 1.2;
	else if (keycode == 89)
		honk->rs = 1.5;
	else if (keycode == 90)
		honk->rs = 2;
	else if (keycode == 91)
		honk->rs = 2.5;
	else if (keycode == 92)
		honk->rs = 3;
	else
		ft_key_pressed_p3(keycode, honk);
}

int			ft_key_pressed(int keycode, t_honk *honk)
{
	if (keycode == 12)
	{
		honk->xrot = (honk->xrot == 2) ? 0 : 2;
		honk->yrot = 0;
		honk->zrot = 0;
	}
	else if (keycode == 69 || keycode == 78)
	{
		if (keycode == 69)
			honk->zoom += honk->zoom >= 5 ? 1 : 0.1;
		else if (keycode == 78)
			honk->zoom -= honk->zoom < 5.1 ? 0.1 : 1;
		if (honk->zoom > 100)
			honk->zoom = 100;
		else if (honk->zoom < 0.2)
			honk->zoom = 0.1;
	}
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		honk->grad = honk->grad == 0 ? 1 : 0;
	else
		ft_key_pressed_p2(keycode, honk);
	return (0);
}
