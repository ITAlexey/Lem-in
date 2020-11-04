/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/10/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static int		update_distance(t_path *path, int ants)
{
	int	cur_steps;
	int	min_steps;
	int	idx;
	int	sum;

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

static void		swap_routes(t_table *node)
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

static void		change_routes(t_path *paths, t_table *src)
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

void			find_solution(t_farm *data, int min_steps)
{
	t_path	*new;
	int		nbr_steps;

	while (data->max_paths && (new = find_path(data)))
	{
		nbr_steps = update_distance(new, data->ants);
		if (!data->paths || (nbr_steps < min_steps))
		{
			clear_paths(data->paths);
			data->paths = new;
			change_routes(data->paths, data->src);
			min_steps = nbr_steps;
			data->max_paths--;
		}
		else
		{
			clear_paths(new);
			break ;
		}
	}
}
