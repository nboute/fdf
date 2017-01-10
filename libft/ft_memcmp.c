/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:17:40 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 19:19:11 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	p1 = (unsigned char*)ptr1;
	p2 = (unsigned char*)ptr2;
	while (i + 1 < n && p1[i] == p2[i])
		i++;
	return ((int)(p1[i] - p2[i]));
}
