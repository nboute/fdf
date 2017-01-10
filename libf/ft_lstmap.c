/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:39:01 by nboute            #+#    #+#             */
/*   Updated: 2016/11/07 17:52:32 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*lst_elem;
	t_list	*tmp;

	lst_elem = NULL;
	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (tmp)
		lst_elem = ft_lstnew(tmp->content, tmp->content_size);
	start = lst_elem;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		lst_elem->next = ft_lstnew(tmp->content, tmp->content_size);
		lst_elem = lst_elem->next;
		lst = lst->next;
	}
	return (start);
}
