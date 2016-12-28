/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:52:36 by nboute            #+#    #+#             */
/*   Updated: 2016/12/28 16:33:38 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_crgb
{
	float		R;
	float		G;
	float		B;
}				t_crgb;

typedef struct	s_chsl
{
	float		H;
	float		S;
	float		L;
}				t_chsl;

#endif
