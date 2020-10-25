//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"
#include <stdio.h>

bool 	find_path(t_farm *data, t_table *src, t_table *sink)
{
	if (!data->route.paths)
		bfs();
	else
	{
		prepare_paths(data, &data->route);
		bfs();
	}
	return (false);
}

int 	count_max_paths(t_farm *data)
{
	t_room	*src;
	t_room	*sink

	src = ((t_room*)data->src->value)->nbr_arcs;
	sink = ((t_room*)data->sink->value)->nbr_arcs;
	data->paths.max = MIN(src, sink);
	data->err = data->paths.max != 0 ? data->err : ERR_PATH;
	return (data->paths.max);
}

int 	main(void)
{
	t_farm		data;
	int 		optimal_flow;
	int 		res;

	optimal_flow = INT_MAX;
	data.fd = open(INPUT, O_RDONLY);
	if (!parse_input(&data) || !count_max_paths(&data))
		throw_error(data);
	while (find_path(&data, data.src, data.sink))
	{
		 if (optimal_flow < current_network)
			 break ;
		 optimal_flow = current_network;
	}
	move_ants();
	close(data.fd);
	return (0);
}

