/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:07:44 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:16:18 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	if ((dup = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	return (ft_strncpy(dup, str, n));
}
