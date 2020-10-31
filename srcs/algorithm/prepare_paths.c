//
// Created by alexey on 21.10.2020.
//

#include "ant_farm.h"

short 	is_equal(void *a, void *b)
{
	return (((t_link*)a)->linked == (t_table*)b);
}

static t_table 		*clone_room(t_table *src, t_table *to)
{
	t_table *clone;
	t_room	*tmp;
	t_link	*link;

	((t_room*)src->value)->tmp = ((t_room*)src->value)->neighbors;
	clone = (t_table*)malloc(sizeof(t_table));
	IF_FAIL(clone);
	ft_memcpy(clone, src, sizeof(t_table));
	tmp = clone->value;
	tmp->in = NULL;
	tmp->nbr_arcs = 1;
	tmp->is_dup = true;
	link = (t_link*)malloc(sizeof(t_link));
	IF_FAIL(link);
	link->linked = to;
	link->is_lock = false;
	tmp->neighbors = ft_lstcreate(link, 0);
	return (clone);
}

t_queue	*copy_route(t_queue *cur)
{
	t_list *lst;
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

void 		prepare_paths(t_path *paths, void *src, void *sink)
{
	t_list	*path;
	t_list	*cur;
	t_list	*prev;
	t_room	*room;

	if (paths)
	{
		path = paths->all;
		while (path)
		{
			cur = path->content;
			prev = NULL;
			while (cur)
			{
				room = ((t_table*)cur->content)->value;
				room->member = prev ? prev->content : src;
				if (cur->content != sink)
				{
					room->route->new = copy_route(room->route->cur);
					room->in = clone_room((t_table*)cur->content, room->member);
				}
				prev = cur;
				cur = cur->next;
			}
			path = path->next;
		}
	}
}