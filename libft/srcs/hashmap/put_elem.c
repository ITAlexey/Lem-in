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

static short	is_collision(t_hashmap *data, t_table *table, int idx, short c)
{
	t_list *cur;

	cur = &data->arr[idx];
	while (cur)
	{
		if (ft_strequ(table->key, ((t_table*)cur->content)->key))
		{
			c = 0;
			remove_table((t_table*)cur->content, data->del);
			cur->content = table;
			break ;
		}
		cur = cur->next;
	}
	if (c)
		ft_lstpushback(&data->arr[idx], ft_lstcreate(table, sizeof(t_table)));
	return (c);
}

static void		*define_case(t_hashmap *data, t_table *table)
{
	int		idx;

	idx = table->hash_code % data->size;
	if (data->arr[idx].content_size == 0)
	{
		data->arr[idx].content = table;
		data->arr[idx].content_size = sizeof(*table);
		data->occupied_cells++;
	}
	else
		data->occupied_cells += is_collision(data, table, idx, 1);
	data->load_factor = data->occupied_cells / (float)data->size;
	return ((void*)table);
}

void			*put_elem(t_hashmap **data, char const *key, void *value)
{
	t_table	*new_table;

	if (*data != NULL)
	{
		new_table = create_table(key, value);
		if (new_table != NULL)
		{
			if ((*data)->load_factor > MAX_LOADING)
				ISNULL(resize_hashmap(data));
			return (define_case(*data, new_table));
		}
	}
	return (NULL);
}
