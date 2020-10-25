//
// Created by alexey on 24.10.2020.
//

#include "ant_farm.h"

static void 	init_errors(char *err_lst[])
{
	err_lst[0] = "Invalid number of ants.";
	err_lst[1] = "Multiple start or end commands.";
	err_lst[2] = "Invalid format line.";
	err_lst[3] = "Invalid format of room name or coordinates.";
	err_lst[4] = "Absent destination rooms.";
	err_lst[5] = "Absent origin rooms.";
	err_lst[6] = "Non-existent room name.";
	err_lst[7] = "Empty lines are forbidden.";
	err_lst[8] = "Paths are not exist.";
}

void 	throw_error(t_farm data)
{
	char 	*errors[ERRORS];

	init_errors(errors);
	ft_printf("ERROR: %s\n", errors[data.err]);
	exit(EXIT_FAILURE);
}