//
// Created by alexey on 21.10.2020.
//

#include "ant_farm.h"

short 	is_equal(void *a, void *b)
{
	return (((t_link*)a)->linked == (t_table*)b);
}

static void 		split_room(t_table *table)
{
	t_table	*room_data;
	t_room	*tmp;
	t_list	*member;

	tmp = table->value;
	member = ft_lstfind(tmp->neighbors, tmp->member, is_equal);
	member->next = NULL;
	room_data = (t_table*)malloc(sizeof(t_table));
	IF_FAIL(room_data);
	ft_memcpy(room_data, table, sizeof(t_table));
	((t_room*)room_data->value)->is_dup = true;
	((t_room*)room_data->value)->in = NULL;
	((t_room*)room_data->value)->neighbors = member;
}

void 		prepare_paths(t_path *paths, void *src, void *sink)
{
	t_list	*path;
	t_list	*cur;

	if (paths)
	{
		path = paths->all;
		while (path)
		{
			cur = path->content;
			while (cur)
			{
				if (cur->content != src && cur->content != sink)
					split_room((t_table*)cur->content);
				cur = cur->next;
			}
			path = path->next;
		}
	}
}