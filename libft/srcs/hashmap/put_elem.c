/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static t_list	*append_table(t_list *lst, t_table *table)
{
	lst->content_size = sizeof(*table);
	lst->content = table;
	return (lst);
}

static t_list	*init_newlst(t_table *table)
{
	t_list	*lst;

	lst = (t_list*)ft_memalloc(sizeof(t_list));
	ISNULL(lst);
	return (append_table(lst, table));
}

static void		*define_case(t_hashmap *data, t_table *table)
{
	int		idx;

	idx = table->hash_code % data->size;
	if (data->arr[idx].content_size == 0)
	{
		ISNULL(append_table(&data->arr[idx], table));
		data->occupied_cells++;
	}
	else if (!ft_strcmp(table->key, ((t_table*)data->arr[idx].content)->key))
	{
		remove_table((t_table*)data->arr[idx].content);
		data->arr[idx].content = table;
	}
	else
	{
		ISNULL(ft_lstpushback(&data->arr[idx], init_newlst(table)));
		data->occupied_cells++;
	}
	data->load_factor = data->occupied_cells / (float)data->size;
	return ((void*)table);
}

void			*put_elem(t_hashmap **data, char const *key,
					void *value, size_t size)
{
	t_table	*new_table;

	if (*data != NULL)
	{
		new_table = create_table(key, value, size);
		if (new_table != NULL)
		{
			if ((*data)->load_factor > MAX_LOADING)
				ISNULL(resize_hashmap(data));
			return (define_case(*data, new_table));
		}
	}
	return (NULL);
}
