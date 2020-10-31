//
// Created by alexey on 27.10.2020.
//

#include "ant_farm.h"

static t_route		*init_route(t_table *to_paste)
{
	t_route	*route;

	route = (t_route*)malloc(sizeof(t_route));
	IF_FAIL(route);
	route->new = init_queue();
	IF_FAIL(route->new);
	enqueue(route->new, to_paste);
	route->cur = init_queue();
	IF_FAIL(route->cur);
	enqueue(route->cur, to_paste);
	return (route);
}

static void 		add_new_route(t_table *tail, t_table *cur)
{
	t_room	*tmp;

	tmp = tail->value;
	if (!tmp->route)
		tmp->route = init_route(cur);
	else
	{
		tmp->route->new = copy_route(tmp->route->cur);
		enqueue(tmp->route->new, cur);
	}
}

static 	void 	lock_passage(t_table *tail, t_table *cur)
{
	t_list	*lst;

	lst = ft_lstfind(((t_room*)tail->value)->neighbors, cur, is_equal);
	((t_link*)lst->content)->is_lock = true;
}

t_path		*restore_path(t_farm *data, t_table *sink)
{
	t_table	*cur;
	t_table *tail;

	cur = sink;
	while (((t_room*)cur->value)->member)
	{
		//printf("cur: [%s]\t", cur->key);
		tail = ((t_room*)cur->value)->member;
		//printf("tail: [%s]\n", tail->key);
		lock_passage(tail, cur);
		add_new_route(tail, cur);
		cur = tail;
	}
	data->paths ? optimization(((t_room*)data->src->value)->route) : 0;
	return (sort_paths(((t_room*)data->src->value)->route->new));
}