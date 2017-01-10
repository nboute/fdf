/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:22:25 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 18:16:08 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *str)
{
	char	*dup;

	if ((dup = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	return (ft_strcpy(dup, str));
}
