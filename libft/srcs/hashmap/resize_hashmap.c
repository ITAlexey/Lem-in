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

static void	put_on_new_place(t_hashmap **newdata, t_list *lst, short counter)
{
	int	place;

	place = ((t_item*)lst->content)->hash_code % (*newdata)->size;
	if ((*newdata)->arr[place].content_size == 0)
	{
		ft_memcpy(&(*newdata)->arr[place], lst, sizeof(t_list));
		if (counter != 0)
			ft_memdel((void**)&lst);
	}
	else
		ft_lstpushback(&(*newdata)->arr[place], lst);
	(*newdata)->occupied_cells++;
}

static void	redirect_lsts(t_hashmap **newdata, t_list *lst)
{
	t_list		*previous;
	short		counter;

	counter = 0;
	while (lst)
	{
		previous = lst;
		lst = lst->next;
		previous->next = NULL;
		put_on_new_place(newdata, previous, counter++);
	}
}

void		*resize_hashmap(t_hashmap **data)
{
	t_hashmap	*new_hashmap;
	int			idx;
	t_list		*current;

	idx = 0;
	new_hashmap = init_hashmap((*data)->size * 2);
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
