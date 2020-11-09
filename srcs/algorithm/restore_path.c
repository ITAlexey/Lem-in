/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/10/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static t_route	*init_route(t_table *to_paste)
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

static void		add_new_route(t_hashmap *rooms, t_table *tail,
					t_table *cur, t_table *src)
{
	t_room	*tmp;

	if (((t_room*)tail->value)->is_dup)
		tail = get_table(rooms, tail->key + 1);
	if (((t_room*)cur->value)->is_dup)
		cur = get_table(rooms, cur->key + 1);
	tmp = tail->value;
	if (!tmp->route)
		tmp->route = init_route(cur);
	else
	{
		if (tail == src)
			tmp->route->new = copy_route(tmp->route->cur);
		enqueue(tmp->route->new, cur);
	}
}

static short	is_equal(void *a, void *b)
{
	return (((t_link*)a)->linked == (t_table*)b);
}

static void		lock_passage(t_hashmap *rooms, t_table *tail, t_table *cur)
{
	t_list	*lst;

	if (((t_room*)tail->value)->is_dup)
		tail = get_table(rooms, tail->key + 1);
	if (((t_room*)cur->value)->is_dup)
		cur = get_table(rooms, cur->key + 1);
	lst = ft_lstfind(((t_room*)tail->value)->neighbors, cur, is_equal);
	((t_link*)lst->content)->is_lock = true;
}

t_path			*restore_path(t_farm *data, t_table *sink)
{
	t_table	*cur;
	t_table *tail;

	cur = sink;
	while (((t_room*)cur->value)->member)
	{
		tail = ((t_room*)cur->value)->member;
		lock_passage(data->rooms, tail, cur);
		add_new_route(data->rooms, tail, cur, data->src);
		cur = tail;
	}
	data->paths ? optimization(((t_room*)data->src->value)->route) : 0;
	return (sort_paths(((t_room*)data->src->value)->route->new));
}
