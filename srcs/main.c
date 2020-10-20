//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"
#include <stdio.h>

void 	print_path(t_hashmap *rooms, t_room *end)
{
	t_room *tmp;

	tmp = end;
	printf("%s", "4");
	while (tmp->member != NULL)
	{
		printf("<-%s", tmp->member);
		tmp = get_elem(rooms, tmp->member);
	}
	printf("\n");
}

short 	find_paths(t_farm *data)
{
	t_room	*start;
	t_room	*end;

	start = get_elem(data->rooms, data->start_room);
	end = get_elem(data->rooms, data->end_room);
	data->max_nbr_paths = MIN(start->nbr_arcs, end->nbr_arcs);
	data->err = data->max_nbr_paths != 0 ? data->err : ERR_PATH;
	if (data->err != -1 || bfs(data) == NULL)
		data->err = ERR_PATH;
	return (data->err);
}

int 	main(void)
{
	t_farm		data;

	if ((data.fd = open(INPUT, O_RDONLY)) > 0)
	{
		if (parse_input(&data) >= 0
			|| find_paths(&data) >= 0)
		{
			ft_printf("ERROR: %s\n", data.err_lst[data.err]);
			exit(EXIT_FAILURE);
		}
		close(data.fd);
	}
	else
	{
		ft_printf("ERROR.");
		exit(EXIT_FAILURE);
	}
	print_path(data.rooms, (t_room*)get_elem(data.rooms, data.end_room));
	return (0);
}

