/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:40:33 by nboute            #+#    #+#             */
/*   Updated: 2016/11/08 20:42:13 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	last;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s)
	{
		while (s[i + 1])
			i++;
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	last = i + 1;
	i = 0;
	if ((str = (char*)malloc(last + 1)) == NULL)
		return (NULL);
	ft_strncpy(str, s, last);
	str[last] = '\0';
	return (str);
}
