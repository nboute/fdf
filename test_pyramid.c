/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pyramid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:57:30 by nboute            #+#    #+#             */
/*   Updated: 2016/11/29 15:02:16 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"

int		main(void)
{
	int		i;
	int		j;
	char	**forme;
	void	*mlx;
	void	*win;

	forme = ft_tabnew(200, 200, '0');
	forme[0][0] = '1';
	forme[0][199] = '1';
	forme[199][0] = '1';
	forme[199][199] = '1';
	forme[99][99] = '5';
	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "pyramid");
	i = 0;
	j = 0;
	while (i < 200)
	{
		ft_putchar('a');
		j = 0;
		while (j < 200)
		{
			if (forme[i][j] != '0')
				mlx_pixel_put(mlx, win, i + 50, j + 50, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
