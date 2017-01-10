/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:47:10 by nboute            #+#    #+#             */
/*   Updated: 2016/11/22 16:45:52 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!c)
		return ((char*)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == ((unsigned char)c))
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
