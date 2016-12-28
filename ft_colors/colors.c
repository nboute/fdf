/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:49:49 by nboute            #+#    #+#             */
/*   Updated: 2016/12/28 21:10:37 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float	ft_hue_to_rgb(float a, float b, float hue)
{
	hue = (hue < 0) ? hue + 1 : hue;
	hue = (hue > 1) ? hue - 1 : hue;
	if ((6 * hue) < 1)
		return (a + (b - a) * 6 * hue);
	if ((2 * hue) < 1)
		return (b);
	if ((3 * hue) < 2)
		return (a + (b - a) * (((float)2 / (float)3) - hue) * 6);
	return (a);
}

float	ft_calc_hue(float max, float del_max, t_crgb *rgb)
{
	float	H;
	float	del_R;
	float	del_G;
	float	del_B;

	del_R = (((max - rgb->R) / 6) + (del_max / 2)) / del_max;
	del_G = (((max - rgb->G) / 6) + (del_max / 2)) / del_max;
	del_B = (((max - rgb->B) / 6) + (del_max / 2)) / del_max;
	if (rgb->R == max)
		H = del_B - del_G;
	else if (rgb->G == max)
		H = (float)1 / (float)3 + del_R - del_B;
	else if (rgb->B == max)
		H = (float)2 / (float)3 + del_G - del_R;
	if (H < 0)
		H += 1;
	if (H > 1)
		H -= 1;
	return (H);
}

t_chsl	*ft_rgb_to_hsl(t_crgb *rgb)
{
	float	min;
	float	max;
	t_chsl	*hsl;

	if (!(hsl = (t_chsl*)malloc(sizeof(t_chsl))))
		return (NULL);
	min = (rgb->R < rgb->G) ? rgb->R : rgb->G;
	min = (rgb->B < min) ? rgb->B : min;
	max = (rgb->R > rgb->G) ? rgb->R : rgb->G;
	max = (rgb->B > max) ? rgb->B : max;
	hsl->L = (min + max) / (float)2;
	if (max - min == 0)
	{
		hsl->H = 0;
		hsl->S = 0;
	}
	else
	{
		hsl->S = (hsl->L < 0.5) ? (max - min) / (max + min) :
				(max - min) / (2 - max - min);
		hsl->H = ft_calc_hue(max, max - min, rgb);
	}
	return (hsl);
}

t_crgb	*ft_hsl_to_rgb(t_chsl *hsl)
{
	t_crgb *rgb;
	float	a;
	float	b;

	if (!(rgb = (t_crgb*)malloc(sizeof(t_crgb))))
		return (NULL);
	if (!hsl->S)
	{
		rgb->R = hsl->L * 255;
		rgb->G = hsl->L * 255;
		rgb->B = hsl->L * 255;
	}
	else
	{
		b = (hsl->L < 0.5) ? hsl->L * (hsl->S + 1) :
			hsl->L + hsl->S - (hsl->S * hsl->L);
		a = 2 * hsl->L - b;
		rgb->R = round((float)255 * ft_hue_to_rgb(a, b, hsl->H + (float)1/ (float)3));
		rgb->G = round((float)255 * ft_hue_to_rgb(a, b, hsl->H));
		rgb->B = round((float)255 * ft_hue_to_rgb(a, b, hsl->H - (float)1/ (float)3));
	}
	return (rgb);
}

void	*ft_convert(float a, float b, float c, char *conv)
{
	void	*color;
	void	*color2;

	color2 = NULL;
	color = ft_new_color(a, b, c, ft_strsub(conv, 0, 3));
	if (!ft_strcmp(conv, "hsl2rgb"))
		color2 = ft_hsl_to_rgb((t_chsl*)color);
	else if (!ft_strcmp(conv, "rgb2hsl"))
		color2 = ft_rgb_to_hsl((t_crgb*)color);
	free(color);
	return (!color2 ? color : color2);
}
