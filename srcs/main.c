/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:27:31 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 20:15:57 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			main(int ac, char **av)
{
	t_honk	honk;
	int		fd;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) <= 2)
		ft_error();
	ft_sethonk(&honk, fd);
	if (honk.ghei <= 1 && honk.gwid <= 1)
		ft_error();
	ft_setscale(&honk);
	ft_set_gradations(&honk);
	ft_setmap(&honk);
	mlx_mouse_hook(honk.win, &ft_mouse_pressed, (void*)&honk);
	mlx_key_hook(honk.win, &ft_key_pressed, (void*)&honk);
	mlx_loop_hook(honk.mlx, &ft_redraw_map, &honk);
	mlx_loop(honk.mlx);
}
