//
// Created by alexey on 21.10.2020.
//

#include "ant_farm.h"

void 	remove_duplicates(t_room *room)
{
	ft_memdel((void**)&room->in);
	ft_memdel((void**)&room->out);
}

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
	t_list	*member;

	member = ft_lstfind(room->neighbors, room->member, is_equal);
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

t_list		*restore_path(t_hashmap rooms, t_table *sink)
{
	t_list	*full_path;
	t_table	*tmp;
	size_t	idx;

	idx = 1;
	full_path = ft_lstcreate(sink, idx++);
	IF_FAIL(full_path);
	tmp = sink
	while (((t_room*)tmp->value)->member)
	{
		tmp = get_table(rooms, ((t_room*)tmp->value)->member);
		ft_lstadd(full_path, ft_lstcreate(tmp, idx++));
	}
	return (full_path);
}

t_list		*get_route(t_hashmap *rooms, t_table *sink, int size)
{
	t_list	*route;
	t_list	*path;

	path = restore_path(rooms, sink);
	route = ft_lstcreate(path, (size_t)size);
	IF_FAIL(route);
	return (route);
}