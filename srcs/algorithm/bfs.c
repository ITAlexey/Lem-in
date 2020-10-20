//
// Created by alexey on 17.10.2020.
//

#include "ant_farm.h"

void 	add_neighbors(t_queue *q, t_hashmap *rooms,
		t_table *room_data, t_hashmap *visited_rooms)
{
	t_list			*tmp;
	t_connection	*link;
	t_table			*current;

	tmp = ((t_room*)room_data->value)->neighbors;
	while (tmp)
	{
		link = (t_connection*)tmp->content;
		current = get_table(rooms, link->room_name);
		if (!is_elem_contained(visited_rooms, current->key))
		{
			((t_room*)current->value)->member = (char*)room_data->key;
			IF_FAIL(put_elem(&visited_rooms, current->key, current->value, sizeof(t_room)));
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
	t_hashmap	*visited_rooms;

	q = init_queue();
	visited_rooms = init_hashmap(TABLE_SIZE);
	start = get_table(data->rooms, data->start_room);
	IF_FAIL(put_elem(&visited_rooms, start->key, start->value, sizeof(t_room)));
	enqueue(q, start);
	while (!is_empty(q))
	{
		current = dequeue(q);
		add_neighbors(q, data->rooms, current, visited_rooms);
	}
	remove_hashmap(visited_rooms);
	remove_queue(q);
	end = get_elem(data->rooms, data->end_room);
	return (end->member);
}