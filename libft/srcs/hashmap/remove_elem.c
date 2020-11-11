/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static void	delete_lst(t_hashmap *data, char const *key, int place)
{
	t_list	*prev;
	t_list	*cur;

	cur = data->arr[place].next;
	prev = NULL;
	while (cur)
	{
		if (!ft_strcmp(((t_table*)cur->content)->key, key))
		{
			remove_table((t_table*)cur->content, data->del);
			if (prev)
				prev->next = cur->next;
			else
				data->arr[place].next = cur->next;
			ft_memdel((void**)cur);
			data->occupied_cells--;
		}
		prev = cur;
		cur = cur->next;
	}
}

static void 	delete_head(t_hashmap *data, int place)
{
	t_list	*cur;
	t_list	*to_delete;

	cur = &data->arr[place];
	to_delete = cur->next;
	remove_table((t_table*)cur->content, data->del);
	if (to_delete)
	{
		cur->content = to_delete->content;
		cur->next = to_delete->next;
		cur->content_size = to_delete->content_size;
		ft_memdel((void**)&to_delete);
	}
	else
	{
		cur->content = NULL;
		cur->content_size = 0;
	}
	data->occupied_cells--;
}

void			remove_elem(t_hashmap *data, char const *key)
{
	int				place;
	t_list			*cur;

	if (data != NULL && key != NULL)
	{
		place = get_hashcode(key) % data->size;
		cur = &data->arr[place];
		if (cur->content_size != 0)
		{
			if (!ft_strcmp(((t_table*)cur->content)->key, key))
				delete_head(data, place);
			else
				delete_lst(data, key, place);
			data->load_factor = data->occupied_cells / (float)data->size;
		}
	}
}
