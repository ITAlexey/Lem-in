//
// Created by alexey on 11.11.2020.
//

#include "hashmap.h"

t_table 	**cast_to_array(t_hashmap *map)
{
	t_table **arr;
	int		idx;
	int 	i;
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