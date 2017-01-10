/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:24:50 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 17:51:35 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next;

	if (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		if (next)
			ft_lstdel(&next, del);
		next = NULL;
	}
}
