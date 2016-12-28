/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:52:36 by nboute            #+#    #+#             */
/*   Updated: 2016/12/28 21:27:33 by nboute           ###   ########.fr       */
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

float	ft_hue_to_rgb(float a, float b, float hue);
float	ft_calc_hue(float max, float del_max, t_crgb *rgb);
t_chsl	*ft_rgb_to_hsl(t_crgb *rgb);
t_crgb	*ft_hsl_to_rgb(t_chsl *hsl);
void	*ft_convert(float a, float b, float c, char *conv);
char	*ft_hsl_to_string(t_chsl *hsl);
char	*ft_rgb_to_string(t_crgb *rgb);
int		ft_rgb_to_int(t_crgb *rgb);
void	*ft_new_color(float a, float b, float c, char *format);

#endif
