/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static void    redirect_lsts(t_hashmap **newdata, t_list *src)
{
	int     place;
	t_table *tmp;

	tmp = src->content;
	place = tmp->hash_code % (*newdata)->size;
	(*newdata)->arr[place].content_size = src->content_size;
	(*newdata)->arr[place].content = src->content;
	(*newdata)->arr[place].next = src->next;
}

void		*resize_hashmap(t_hashmap **data)
{
	t_hashmap	*new_hashmap;
	int			idx;
	t_list		*current;

	idx = 0;
	new_hashmap = init_hashmap((*data)->size * 2, (*data)->del);
	ISNULL(new_hashmap);
	while (idx < (*data)->size)
	{
		if ((*data)->arr[idx].content_size != 0)
		{
			current = &(*data)->arr[idx];
			redirect_lsts(&new_hashmap, current);
		}
		idx++;
	}
	ft_memdel((void**)&((*data)->arr));
	ft_memdel((void**)data);
	*data = new_hashmap;
	return ((void*)new_hashmap);
}
