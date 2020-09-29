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

static void	delete_lst(t_hashmap *data, t_list **head, t_list *lst,
				char const *to_find)
{
	t_list	*prev;
	t_list	*cur;
	int		place;

	place = 0;
	cur = lst;
	while (cur)
	{
		if (!ft_strcmp(((t_table*)cur->content)->key, to_find))
		{
			remove_table((t_table*)cur->content);
			del_finded(place == 0 ? head : &prev, cur);
			data->occupied_cells--;
			break ;
		}
		prev = cur;
		cur = cur->next;
		place++;
	}
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
				remove_table((t_table*)current->content);
				data->occupied_cells--;
			}
			else
				delete_lst(data, &current, current->next, key);
		}
	}
}
