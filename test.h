/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:59:52 by nboute            #+#    #+#             */
/*   Updated: 2016/12/29 14:24:41 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H

#include "ft_colors/color.h"
# define HUE 65
# define SAT 0.5
typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		_x;
	double		_y;
	double		_z;
	t_chsl*		color;
}				t_point;

#endif
