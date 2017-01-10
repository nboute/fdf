/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:03:04 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:55:59 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;
	size_t	i;

	i = 0;
	ptrd = (char*)dest;
	ptrs = (char*)src;
	if (ptrd == ptrs)
		return (dest);
	if (ptrd > ptrs)
	{
		while (n)
		{
			n--;
			ptrd[n] = ptrs[n];
		}
	}
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}
