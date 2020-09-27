/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:41:49 by dshala            #+#    #+#             */
/*   Updated: 2020/09/19 12:57:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	*ft_lstpushback(t_list *head, t_list *node)
{
	t_list	*cur;

	if (head != NULL && node != NULL)
	{
		cur = head;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
		return (node);
	}
	return (NULL);
}
