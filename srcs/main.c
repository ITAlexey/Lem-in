//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"

int 	main(void)
{
	t_farm		data;
	t_room		*room;
	data.fd = open(INPUT, O_RDONLY);
	if (!parse_input(&data, 0, 0))
		throw_error(data);
	find_solution(&data, INT_MAX);
	//move_ants();
	//print_path(data.paths);
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	close(data.fd);
	return (0);
}

