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

static void	del_finded(t_list **head, t_list *current)
{
	(*head)->next = current->next;
	ft_memdel((void**)&current);
}

static short	delete_lst(t_list **head, t_list *lst,
				char const *to_find, void (*del)(void *))
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = lst;
	while (cur)
	{
		if (!ft_strcmp(((t_table*)cur->content)->key, to_find))
		{
			remove_table((t_table*)cur->content, del);
			del_finded(prev ? &prev : head, cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

void		remove_elem(t_hashmap *data, char const *key)
{
	unsigned int	hash_code;
	int				place;
	t_list			*current;

	if (data != NULL && key != NULL)
	{
		hash_code = get_hashcode(key);
		place = hash_code % data->size;
		current = &data->arr[place];
		if (current->content_size != 0)
		{
			if (!ft_strcmp(((t_table*)current->content)->key, key))
			{
				current->content_size = 0;
				remove_table((t_table*)current->content, data->del);
				data->occupied_cells--;
			}
			else
				data->occupied_cells -= delete_lst(&current,
						current->next, key, data->del);
		}
		data->load_factor = data->occupied_cells / (float)data->size;
	}
}
