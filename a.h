/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:59:51 by nboute            #+#    #+#             */
/*   Updated: 2016/12/15 03:39:24 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H

#include "test.h"
# define A_H

# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define BROWN 0x00663300
# define WHITE 0x00FFFFF
# define PRE 500

typedef struct s_honk
{
	void *mlx;
	void *win;
	void *img;

	int bpx;
	int size;
	int endian;
	int prex;
	int prey;
	float	zoom;
	int	xang;
	int	yang;
	int	zang;

	int width;
	int height;
	t_point		**grid;
	int		gwid;
	int		ghei;
	int		xrange;
	int		yrange;
	int		zrange;
	int		minval;
	char	*data;
	unsigned int color;

}				t_honk;

#endif
