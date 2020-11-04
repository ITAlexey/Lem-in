/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/10/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static t_table	*clone_room(t_table *src)
{
	t_table	*clone;
	t_room	*tmp;

	clone = (t_table*)malloc(sizeof(t_table));
	IF_FAIL(clone);
	clone->value = (t_room*)malloc(sizeof(t_room));
	clone->key = src->key;
	IF_FAIL(clone->value);
	tmp = clone->value;
	tmp->member = ((t_room*)src->value)->member;
	tmp->in = NULL;
	tmp->nbr_arcs = 1;
	tmp->is_dup = true;
	return (clone);
}

t_queue			*copy_route(t_queue *cur)
{
	t_list	*lst;
	t_queue	*new;

	lst = cur->head;
	new = init_queue();
	IF_FAIL(new);
	while (lst)
	{
		enqueue(new, lst->content);
		lst = lst->next;
	}
	return (new);
}

static void		reconfiguration(t_list *cur, t_list *prev,
						void *src, void *sink)
{
	t_room	*room;

	while (cur)
	{
		room = ((t_table*)cur->content)->value;
		room->member = prev ? prev->content : src;
		if (cur->content != sink)
		{
			room->route->new = copy_route(room->route->cur);
			room->in = clone_room((t_table*)cur->content);
		}
		prev = cur;
		cur = cur->next;
	}
}

void			prepare_paths(t_path *paths, void *src, void *sink)
{
	t_list	*path;

	if (paths)
	{
		path = paths->all;
		while (path)
		{
			reconfiguration(path->content, NULL, src, sink);
			path = path->next;
		}
	}
}
