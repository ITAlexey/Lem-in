/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_table	**cast_to_array(t_hashmap *map)
{
	t_table **arr;
	int		idx;
	int		i;
	t_list	*cur;

	i = 0;
	idx = 0;
	arr = malloc(sizeof(t_table*) * (map->occupied_cells + 1));
	if (!arr)
		return (NULL);
	while (i < map->size)
	{
		cur = &map->arr[i];
		if (cur->content_size != 0)
		{
			while (cur)
			{
				arr[idx++] = (t_table*)cur->content;
				cur = cur->next;
			}
		}
		i++;
	}
	arr[idx] = NULL;
	return (arr);
}
