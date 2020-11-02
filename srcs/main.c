//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"

int 	main(void)
{
	t_farm		data;

	data.fd = open(INPUT, O_RDONLY);
	if (!parse_input(&data, STR_MSG, END_MSG))
		throw_error(data);
	find_solution(&data, MIN_STEPS);
	//print_solution(data.paths, data.ants, ANTS_REACHED_TO_END);
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	close(data.fd);
	return (0);
}

