/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:40:07 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/19 12:57:40 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

static void		ft_list_clear(t_list *begin_list)
{
	t_list *to_free;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		to_free = begin_list;
		begin_list = (begin_list)->next;
		free(to_free);
	}
	begin_list = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			ft_list_clear(new);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
