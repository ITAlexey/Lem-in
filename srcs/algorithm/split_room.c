//
// Created by alexey on 21.10.2020.
//

#include "ant_farm.h"

short 	is_equal(void *a, void *b)
{
	char	*str;
	t_link	*link;

	link = (t_link*)a;
	str = (char*)b;
	return ((short)ft_strequ(str, link->room_name));
}

void 		split_room(t_farm *data, t_table *table)
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
	room_data->is_dup = true;
	room_data->in = NULL;
	room_data->neighbors = member;
}

void 		prepare_paths(t_farm *data, t_path *path)
{
	t_list	*route;
	t_list	*cur;

	route = path->routes;
	while (route)
	{
		cur = route->content;
		while (cur)
		{
			if (cur->content != data->src && cur->content != data->sink)
				split_room(data, (t_table*)cur->content);
			cur = cur->next;
		}
		route = route->next;
	}
}

t_path		*optimize_path(void)
{
	// check_collusions
	return (sort_paths());
}

t_path		*restore_path(t_data *data, t_table *sink)
{
	t_table	*cur;
	t_table *tail;
	t_room	*tmp;
	t_path	*new;
	t_list	*lst;

	new = (t_path*)malloc(sizeof(t_path));
	IF_FAIL(new);
	data->paths ? ft_memecpy(new, prev, sizeof(t_path)) : 0;
	cur = sink;
	while (((t_room*)cur->value)->member)
	{
		tail = ((t_room*)cur->value)->member;
		tmp = tail->value;
		lst = ft_lstfind(tmp->neighbors, cur->key, is_equal);
		((t_link*)lst->content)->is_lock = true;
		tmp->in ? ft_memdel((void**)&tmp->in) : 0;
		cur = tail;
	}
	return (optimize_path());
}