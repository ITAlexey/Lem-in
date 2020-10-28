//
// Created by alexey on 26.10.2020.
//

#include "ant_farm.h"

static int	expression(int *lengths, int idx)
{
	int 	ret;
	int 	tmp;

	ret = 0;
	tmp = idx;
	while (idx > 0)
		ret += lengths[tmp] - lengths[--idx];
	return (ret);
}

static int 	calculate_steps(t_path *path, int min, int ants)
{
	size_t	len;
	int 	result;
	int 	idx;

	result = 0;
	idx = 0;
	while (ants)
	{
		idx = idx == path->found ? 0 : idx;
		if (ants > expression(path->lengths, idx))
			result++;
		else
			break ;
		idx++;
		ants--;
	}
	return (result);
}

int		compare_paths(t_path *prev, t_path *new, int min_steps, int ants)
{
	if (!prev)
	{
		return (calculate_steps(new, min_steps, ants));
	}
	return (0);
}

void 		find_solution(t_farm *data, int min_steps, int max)
{
	int 	nbr_steps;
	t_path	*new;

	while ((new = find_path(data, data->src, data->sink)))
	{
		nbr_steps = compare_paths(data->paths, new, min_steps, data->ants);
		if (min_steps < nbr_steps)
		{
			clear_paths(new);
			break ;
		}
		min_steps = nbr_steps;
		clear_paths(data->paths);
		data->paths = new;
	}
}