/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 20:49:21 by nboute            #+#    #+#             */
/*   Updated: 2016/12/28 21:46:32 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int		main(int ac, char **av)
{
	void	*color;

	if (ac != 5)
		return (0);
	color = ft_new_color(atof(av[1]), atof(av[2]), atof(av[3]), av[4]);
	printf("0x%08x\n", ft_rgb_to_int((t_crgb*)color));
}
