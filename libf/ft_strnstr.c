/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:28:27 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:33:00 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && s1[i + j] && (i + j) < n)
		{
			if (!s2[j + 1])
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
