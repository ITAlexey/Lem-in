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
		t_table *room_data, t_hashmap *visited)
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
		cur = link->linked;
		if (!link->is_lock && !is_elem_contained(visited, cur->key))
		{
			((t_room*)cur->value)->member = room_data;
			IF_FAIL(put_elem(&visited, cur->key, cur->value, sizeof(t_room)));
			enqueue(q, analyse_room(room_data, cur));
		}
		tmp = tmp->next;
	}
}

t_bfs		*init_bfs(t_table *src)
{
	t_bfs	*search;

	search = (t_bfs*)malloc(sizeof(t_bfs));
	IF_FAIL(search);
	search->is_exist = false;
	search->q = init_queue();
	search->visited = init_hashmap(TABLE_SIZE);
	IF_FAIL(put_elem(&search->visited, src->key, src->value, sizeof(t_room)));
	enqueue(q, src);
}

static void 	clear_bfs(t_bfs *search)
{
	remove_hashmap(search->visited);
	remove_queue(search->q);
	ft_memdel((void**)&search);
}

t_path		*find_path(t_farm *data, t_table *src, t_table *sink)
{
	t_bfs		*search;
	t_table		*cur;

	search = init_bfs(src);
	data->paths ? prepare_paths(data, data->paths) : 0;
	while (!is_empty(search->q))
	{
		cur = dequeue(search->q);
		if (cur == sink && (search->is_exist = true))
			break ;
		add_neighbors(search->q, data->rooms, cur, search->visited);
	}
	clear_bfs(search);
	return (path_exist ? restore_path(data, sink) : NULL);
}