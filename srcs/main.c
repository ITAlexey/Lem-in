//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"

int 	main(void)
{
	t_farm		data;

	data.fd = open(INPUT, O_RDONLY);
	if (!parse_input(&data, 0, 0))
		throw_error(data);
	find_solution(&data, INT_MAX, data.max_paths);
	//move_ants();
	clear_memory(&data);
	close(data.fd);
	return (0);
}

