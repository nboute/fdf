/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:29:59 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:56:09 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char		*ptr2;
	size_t		i;

	i = 0;
	ptr2 = (char*)ptr;
	while (i < num)
		ptr2[i++] = (unsigned char)value;
	return (ptr);
}
