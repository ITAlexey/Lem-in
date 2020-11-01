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

static void 		f1(t_table *node, t_bfs *bfs)
{
	t_list		*tmp;
	t_table		*cur;

	tmp = ((t_room*)node->value)->neighbors;
	if (((t_room*)node->value)->in)
		enqueue(bfs->q, ((t_room*)node->value)->in);
	while (tmp)
	{
		cur = ((t_link*)tmp->content)->linked;
		if (!((t_link*)tmp->content)->is_lock && !get_elem(bfs->visited, cur->key))
		{
			((t_room*)cur->value)->member = node;
			IF_FAIL(put_elem(&bfs->visited, cur->key, cur->value, sizeof(t_room)));
			enqueue(bfs->q, analyse_room(node, cur));
		}
		tmp = tmp->next;
	}
}

static void 		f(t_table *node, t_bfs *bfs, t_hashmap *rooms)
{
	t_table		*member;

	member = ((t_room*)node->value)->member;
	printf(" in");
	if (!is_elem_contained(bfs->visited, member->key))
	{
		((t_room*)member->value)->member = get_table(rooms, node->key);
		enqueue(bfs->q, member);
		IF_FAIL(put_elem(&bfs->visited, member->key, member->value, sizeof(t_room)));
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
		((t_room*)cur->value)->is_dup ? f(cur, search, data->rooms) : f1(cur, search);
	}
	remove_hashmap(search->visited);
	remove_queue(search->q);
	ft_memdel((void**)&search);
	return (is_exist ? restore_path(data, sink) : NULL);
}