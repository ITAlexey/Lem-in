//
// Created by alexey on 26.10.2020.
//

#include "ant_farm.h"

t_path 		*compare_paths(t_path *prev, t_path *new)
{
	if (!prev)
		return (new);

}

void 		clear_path(t_path *path)
{
	ft_lstclr(path->routes);
	ft_memdel((void**)&path);
}

void 		find_solution(t_farm *data, int min_steps, int max)
{
	int 	nbr_steps;
	t_path	*new;

	while (data->paths.found < max && (new = find_path(data, data->src, data->sink)))
	{
		nbr_steps = compare_paths(data->paths, new, min_steps);
		if (min_steps < nbr_steps)
		{
			clear_path(new);
			break ;
		}
		min_steps = nbr_steps;
		clear_path(data->paths);
		data->paths = new;
	}
}