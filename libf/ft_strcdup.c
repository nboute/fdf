/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:15:25 by nboute            #+#    #+#             */
/*   Updated: 2016/11/22 19:29:12 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *str, int c)
{
	char	*dup;

	dup = (char*)malloc(ft_strclen(str, c) + 1);
	return (ft_strccpy(dup, str, c));
}
