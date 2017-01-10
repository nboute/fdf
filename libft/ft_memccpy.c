/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:55:04 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 17:53:02 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	i = 0;
	ptrd = (unsigned char*)dest;
	ptrs = (unsigned char*)src;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrd[i] == (unsigned char)c)
			return ((void*)(ptrd + i + 1));
		i++;
	}
	return (NULL);
}
