/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static t_list	*append_item(t_list *lst, t_item *item)
{
	lst->content_size = sizeof(*item);
	lst->content = item;
	return (lst);
}

static t_list	*init_newlst(t_item *item)
{
	t_list	*lst;

	lst = (t_list*)ft_memalloc(sizeof(t_list));
	ISNULL(lst);
	return (append_item(lst, item));
}

static void		*define_case(t_hashmap *data, t_item *item)
{
	int		idx;

	idx = item->hash_code % data->size;
	if (data->arr[idx].content_size == 0)
	{
		ISNULL(append_item(&data->arr[idx], item));
		data->occupied_cells++;
	}
	else if (!ft_strcmp(item->key, ((t_item*)data->arr[idx].content)->key))
	{
		remove_item((t_item*)data->arr[idx].content);
		data->arr[idx].content = item;
	}
	else
	{
		ISNULL(ft_lstpushback(&data->arr[idx], init_newlst(item)));
		data->occupied_cells++;
	}
	data->load_factor = data->occupied_cells / (float)data->size;
	return ((void*)item);
}

void			*put_elem(t_hashmap **data, t_item *item)
{
	if (item != NULL && *data != NULL)
	{
		if ((*data)->load_factor > MAX_LOADING)
			ISNULL(resize_hashmap(data));
		return (define_case(*data, item));
	}
	return (NULL);
}
