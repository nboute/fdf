/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:59:51 by nboute            #+#    #+#             */
/*   Updated: 2017/01/03 20:46:36 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
# define A_H

# include "test.h"

# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define RED 0x00FF0000
# define PINK 0x00FF3399
# define TURQUOISE 0x00CCCC
# define VIOLET 0x00990099
# define BROWN 0x00663300
# define WHITE 0x00FFFFFF
# define PRE 500
# define ROT 1

typedef struct			s_readlines
{
	char				**tab;
	struct s_readlines	*next;
}						t_readlines;

typedef struct			s_honk
{
	void				*mlx;
	void				*win;
	void				*img;

	int					bpx;
	int					size;
	int					endian;
	int					prex;
	int					prey;
	float				zoom;
	float				xang;
	float				yang;
	float				zang;
	int					xrot;
	int					yrot;
	int					zrot;
	int					color;
	int					k;

	int					width;
	int					height;
	t_point				**grid;
	int					gwid;
	int					ghei;
	int					xrange;
	int					yrange;
	int					zrange;
	int					minval;
	char				*data;

}						t_honk;

#endif
