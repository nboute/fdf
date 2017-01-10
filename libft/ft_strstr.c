/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:17:17 by nboute            #+#    #+#             */
/*   Updated: 2016/11/14 09:27:51 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && s1[i + j])
		{
			if (!s2[j + 1])
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
