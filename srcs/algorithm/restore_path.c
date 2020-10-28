//
// Created by alexey on 27.10.2020.
//

#include "ant_farm.h"

static t_route		*init_route(t_table *to_paste)
{
	t_route	*route;

	route = (t_route*)malloc(sizeof(t_route));
	IF_FAIL(route);
	route->cur = init_queue();
	IF_FAIL(route->cur);
	route->new = init_queue();
	IF_FAIL(route->new);
	enqueue(route->cur, to_paste);
	enqueue(route->new, to_paste);
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
		tmp->route->new = init_queue();
		IF_FAIL(tmp->route->new);
		ft_memcpy(tmp->route->new, tmp->route->new, sizeof(t_queue));
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
		tail = ((t_room*)cur->value)->member;
		lock_passage(tail, cur);
		add_new_route(tail, cur);
		((t_room*)tail->value)->in ? ft_memdel((void**)&((t_room*)tail->value)->in) : 0;
		cur = tail;
	}
	optimization(((t_room*)data->src->value)->route);
	return (sort_paths(((t_room*)data->src->value)->route->new));
}