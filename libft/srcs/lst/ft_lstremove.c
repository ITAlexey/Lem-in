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

static void	delete_list(t_list *cur, t_list **prev)
{
	*prev = cur->next;
	ft_memdel(&cur->content);
	ft_memdel((void**)&cur);
}

static void	delete_head(t_list **head, t_list *current)
{
	*head = (*head)->next;
	ft_memdel(&current->content);
	ft_memdel((void**)&current);
}

void		ft_lstremove(t_list **lst, void *to_find,
					short (*predic)(void *, void *))
{
	t_list	*current;
	t_list	*previous;
	int		place;

	if (lst != NULL && *lst != NULL && predic != NULL)
	{
		place = 0;
		current = *lst;
		while (current)
		{
			if (predic(current->content, to_find))
			{
				place == 0 ? delete_head(lst, current) :
							delete_list(current, &previous);
				break ;
			}
			place++;
			previous = current;
			current = current->next;
		}
	}
}
