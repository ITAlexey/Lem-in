//
// Created by alexey on 27.10.2020.
//

#include "ant_farm.h"

static bool	is_collision(t_table *pattern, t_route *route)
{
	t_queue	*q;
	t_table	*tmp;
	t_queue	*nodes;
	bool	is_match;

	is_match = false;
	if (route)
	{
		nodes = route->new;
		q = init_queue();
		while ((tmp = dequeue(nodes)))
		{
			if (pattern == tmp && (is_match = true))
				continue;
			enqueue(q, tmp);
		}
		remove_queue(route->new);
		route->new = q;
	}
	return (is_match);
}

void		find_collisions(t_table *pattern, t_route *route)
{
	t_queue	*q;
	t_table	*tmp;
	t_queue	*nodes;

	if (route)
	{
		nodes = route->new;
		q = init_queue();
		while ((tmp = dequeue(nodes)))
		{
			if (is_collision(pattern, ((t_room*)tmp->value)->route))
				continue ;
			enqueue(q, tmp);
		}
		remove_queue(route->new);
		route->new = q;
		optimization(route);
	}
}

void 		optimization(t_route *route)
{
	t_table	*tmp;
	t_list	*lst;

	if (route)
	{
		lst = route->new->head;
		while (lst)
		{
			tmp = lst->content;
			find_collisions(tmp, ((t_room*)tmp->value)->route);
			lst = lst->next;
		}
	}
}