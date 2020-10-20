//
// Created by alexey on 17.10.2020.
//

#include "ant_farm.h"

void 	add_neighbors(t_queue *q, t_hashmap *rooms, t_table *room_data)
{
	t_list			*tmp;
	t_connection	*link;
	t_table			*current;

	tmp = ((t_room*)room_data->value)->neighbors;
	while (tmp)
	{
		link = (t_connection*)tmp->content;
		current = get_table(rooms, link->room_name);
		if (!((t_room*)current->value)->is_visited)
		{
			((t_room*)current->value)->member = room_data->key;
			((t_room*)current->value)->is_visited = true;
			enqueue(q, current);
		}
		tmp = tmp->next;
	}
}

char		*bfs(t_farm *data)
{
	t_queue		*q;
	t_table		*current;
	t_table		*start;
	t_room		*end;

	q = init_queue();
	start = get_table(data->rooms, data->start_room);
	((t_room*)start->value)->is_visited = true;
	enqueue(q, start);
	while (!is_empty(q))
	{
		current = dequeue(q);
		add_neighbors(q, data->rooms, current);
	}
	remove_queue(q);
	end = get_elem(data->rooms, data->end_room);
	return (end->member);
}