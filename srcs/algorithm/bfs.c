//
// Created by alexey on 17.10.2020.
//

#include "ant_farm.h"

static inline t_table	*analyse_room(t_table* main, t_table *neighbor)
{
	t_room	*main_room;
	t_room	*link_room;

	main_room = main->value;
	link_room = neighbor->value;
	return (!main_room->is_dup && link_room->in ? link_room->in : neighbor);
}

void 	add_neighbors(t_queue *q, t_hashmap *rooms,
		t_table *room_data, t_hashmap *visited_rooms)
{
	t_list		*tmp;
	t_link		*link;
	t_table		*cur;

	tmp = ((t_room*)room_data->value)->neighbors;
	if (((t_room*)room_data->value)->in)
		enqueue(q, ((t_room*)room_data->value)->in);
	while (tmp)
	{
		link = tmp->content;
		cur = get_table(rooms, link->room_name);
		if (!link->is_lock && !is_elem_contained(visited_rooms, cur->key))
		{
			((t_room*)cur->value)->member = (char*)room_data->key;
			IF_FAIL(put_elem(&visited_rooms, cur->key, cur->value, sizeof(t_room)));
			enqueue(q, analyse_room(room_data, cur));
		}
		tmp = tmp->next;
	}
}

t_list		*bfs(t_farm *data, t_table *src, t_table *sink)
{
	t_queue		*q;
	t_table		*cur;
	bool		path_exist;
	t_hashmap	*visited_rooms;

	path_exist = false;
	q = init_queue();
	visited_rooms = init_hashmap(TABLE_SIZE);
	IF_FAIL(put_elem(&visited_rooms, src->key, src->value, sizeof(t_room)));
	enqueue(q, start);
	while (!is_empty(q))
	{
		cur = dequeue(q);
		if (cur == sink)
		{
			path_exist = true;
			break ;
		}
		add_neighbors(q, data->rooms, cur, visited_rooms);
	}
	remove_hashmap(visited_rooms);
	remove_queue(q);
	return (path_exist ? get_route() : NULL);
}