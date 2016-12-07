/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:59:51 by nboute            #+#    #+#             */
/*   Updated: 2016/12/07 21:38:18 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H

#include "test.h"
# define A_H

# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define BROWN 0x00663300
# define WHITE 0x00FFFFF
# define ZO 50

typedef struct s_honk
{
	void *mlx;
	void *win;
	void *img;

	int bpx;
	int size;
	int endian;

	int width;
	int height;
	t_point		**grid;
	int		gwid;
	int		ghei;
	char	*data;
	unsigned int color;

}				t_honk;

#endif
