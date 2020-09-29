/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

t_value	*get_elem(t_hashmap *data, char const *key)
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
			while (current != NULL)
			{
				if (!ft_strcmp(((t_table*)current->content)->key, key))
					return (&((t_table*)current->content)->value);
				current = current->next;
			}
		}
	}
	return (NULL);
}
