/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:58:43 by nboute            #+#    #+#             */
/*   Updated: 2016/11/29 14:41:53 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(int y, int x, char c)
{
	int		i;
	int		j;
	char	**tab;

	if ((tab = (char**)malloc(sizeof(char*) * (y + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		if ((tab[i] = (char*)malloc(x + 1)) == NULL)
			return (NULL);
		j = 0;
		while (j < x)
			tab[i][j++] = c;
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
