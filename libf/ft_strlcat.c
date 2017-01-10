/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:41:21 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:11:22 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen((const char*)dest);
	srclen = ft_strlen(src);
	if (n <= destlen)
		return (srclen + n);
	ft_strncat(dest, src, n - destlen - 1);
	return (destlen + srclen);
}
