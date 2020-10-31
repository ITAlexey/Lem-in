//
// Created by alexey on 26.10.2020.
//

#include "ant_farm.h"

void 		print_queue(t_queue *q)
{
	t_list *lst;

	lst = q->head;
	while (lst)
	{
		printf("[%s] ", ((t_table*)lst->content)->key);
		lst = lst->next;
	}
	printf("\n");
}

static int		update_distance(t_path *path, int ants)
{
	int 	cur_steps;
	int 	min_steps;
	int 	idx;
	int 	sum;

	idx = 0;
	sum = 0;
	min_steps = INT_MAX;
	while (idx < path->found)
	{
		sum += path->lengths[idx] - 1;
		cur_steps = (ants + sum + idx) / (idx + 1) - 1;
		if (cur_steps >= min_steps)
			break ;
		min_steps = cur_steps;
		idx++;
	}
	return (min_steps);
}

static void 		swap_routes(t_table *node)
{
	t_route		*r;

	r = ((t_room*)node->value)->route;
	if (r)
	{
		remove_queue(r->cur);
		r->cur = r->new;
		r->new = NULL;
	}
}

static void 		change_routes(t_path *paths, t_table *src)
{
	t_list	*path;
	t_list	*elem;

	path = paths->all;
	swap_routes(src);
	while (path)
	{
		elem = path->content;
		while (elem)
		{
			swap_routes((t_table*)elem->content);
			elem = elem->next;
		}
		path = path->next;
	}
}

void 		find_solution(t_farm *data, int min_steps)
{
	t_path	*new;
	int 	count_paths;
	int 	nbr_steps;

	count_paths = 0;
	while (count_paths < data->max_paths &&
			(new = find_path(data, data->src, data->sink)))
	{
		nbr_steps = update_distance(new, data->ants);
		if (!data->paths || nbr_steps < min_steps)
		{
			clear_paths(data->paths);
			data->paths = new;
			//print_path(data->paths);
			change_routes(data->paths, data->src);
			min_steps = nbr_steps;
			count_paths++;
		}
		else
		{
			clear_paths(new);
			break;
		}
	}
}