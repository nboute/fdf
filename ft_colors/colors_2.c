/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 20:15:11 by nboute            #+#    #+#             */
/*   Updated: 2016/12/28 21:39:56 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "color.h"
#include "../libft/libft.h"

char	*ft_hsl_to_string(t_chsl *hsl)
{
	int		i;
	short	h;
	short	s;
	short	l;
	char	*str;

	h = (short)(hsl->H * 360);
	s = (short)(hsl->S * 100);
	l = (short)(hsl->L * 100);
	if (!(str = (char*)malloc(sizeof(char) * 10)))
			return (NULL);
	i = 0;
	str[i++] = h / 100 + '0';
	str[i++] = (h / 10) % 10 + '0';
	str[i++] = h % 100 + '0';
	str[i++] = s / 100 + '0';
	str[i++] = (s / 10) % 10 + '0';
	str[i++] = s % 100 + '0';
	str[i++] = l / 100 + '0';
	str[i++] = (l / 10) % 10 + '0';
	str[i++] = l % 100 + '0';
	return (str);
}

char	*ft_rgb_to_string(t_crgb *rgb)
{
	int		i;
	short	r;
	short	g;
	short	b;
	char	*str;

	r = (short)(rgb->R * 255);
	g = (short)(rgb->G * 255);
	b = (short)(rgb->B * 255);
	if (!(str = (char*)malloc(sizeof(char) * 14)))
			return (NULL);
	i = 4;
	ft_strcpy(str, "0x00");
	str[i++] = r / 100 + '0';
	str[i++] = (g / 10) % 10 + '0';
	str[i++] = b % 100 + '0';
	str[i++] = r / 100 + '0';
	str[i++] = (g / 10) % 10 + '0';
	str[i++] = b % 100 + '0';
	str[i++] = r / 100 + '0';
	str[i++] = (g / 10) % 10 + '0';
	str[i++] = b % 100 + '0';
	return (str);
}

void	*ft_new_color(float a, float b, float c, char *format)
{
	void	*color;

	color = NULL;
	if (!ft_strcmp(format, "hsl"))
	{
		color = malloc(sizeof(t_chsl));
		((t_chsl*)color)->H = a;
		((t_chsl*)color)->S = b;
		((t_chsl*)color)->L = c;
	}
	else if (!ft_strcmp(format, "rgb"))
	{
		color = malloc(sizeof(t_crgb));
		((t_crgb*)color)->R = a;
		((t_crgb*)color)->G = b;
		((t_crgb*)color)->B = c;
	}
	return (color);
}

int		ft_rgb_to_int(t_crgb *rgb)
{
	int	value;

	value = rgb->R;
	value = (value << 8) + rgb->G;
	value = (value << 8) + rgb->B;
	return (value);
}
