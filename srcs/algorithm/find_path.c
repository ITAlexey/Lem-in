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

static void 	add_neighbors(t_queue *q, t_table *room_data, t_hashmap *visited)
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

static t_bfs		*init_bfs(t_table *src)
{
	t_bfs	*search;

	search = (t_bfs*)malloc(sizeof(t_bfs));
	IF_FAIL(search);
	search->q = init_queue();
	search->visited = init_hashmap(TABLE_SIZE, NULL);
	IF_FAIL(put_elem(&search->visited, src->key, src->value, sizeof(t_room)));
	enqueue(search->q, src);
	return (search);
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
	bool		is_exist;

	search = init_bfs(src);
	is_exist = false;
	prepare_paths(data->paths, src, sink);
	while (!is_empty(search->q))
	{
		cur = dequeue(search->q);
		if (cur == sink && (is_exist = true))
			break ;
		add_neighbors(search->q, cur, search->visited);
	}
	clear_bfs(search);
	return (is_exist ? restore_path(data, sink) : NULL);
}