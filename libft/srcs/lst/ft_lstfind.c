/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:07:53 by dshala            #+#    #+#             */
/*   Updated: 2019/10/03 15:51:53 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list		*ft_lstfind(t_list *head, void *to_find,
				short (*predic)(void *, void *))
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (predic(tmp->content, to_find))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
