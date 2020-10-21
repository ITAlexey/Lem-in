/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:07:53 by dshala            #+#    #+#             */
/*   Updated: 2020/10/03 15:51:53 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "libft.h"

void		ft_lstremove(t_list **head, void *to_find,
					short (*predic)(void *, void *))
{
	t_list	*cur;
	t_list	*prev;

	if (head != NULL && *head != NULL && predic != NULL)
	{
		prev = NULL;
		cur = *head;
		while (cur)
		{
			if (predic(cur->content, to_find))
			{
				if (!prev)
					*head = (*head)->next;
				else
					prev->next = cur->next;
				ft_memdel(&cur->content);
				ft_memdel((void**)cur);
				break ;
			}
			prev = cur;
			cur = cur->next;
		}
	}
}
