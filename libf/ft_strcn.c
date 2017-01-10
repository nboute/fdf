/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:02:45 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 14:04:35 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcn(char *str, int c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			n++;
		i++;
	}
	return (n);
}