/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static void	clear_lsts(t_list *lst, void (*del)(void *))
{
	t_list	*to_delete;

	while (lst != NULL)
	{
		to_delete = lst;
		lst = lst->next;
		remove_table((t_table*)to_delete->content, del);
		ft_memdel((void**)&to_delete);
	}
}

void		remove_hashmap(t_hashmap *data)
{
	int	idx;

	idx = 0;
	while (idx < data->size)
	{
		if (data->arr[idx].content_size != 0)
		{
			if (data->arr[idx].next != NULL)
				clear_lsts(data->arr[idx].next, data->del);
			remove_table((t_table*)data->arr[idx].content, data->del);
		}
		idx++;
	}
	ft_memdel((void**)&data->arr);
	ft_memdel((void**)&data);
}
