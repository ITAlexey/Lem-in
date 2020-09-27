//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"
#define INPUT "input.txt"

int 	main(int ac, char *av[])
{
	int const	fd;
	char 		*line;
	t_farm		data;

	if (ac == 2)
	{
		// first line contains number_of_ants
		//
		if ((fd = open(INPUT, O_RDONLY)) > 0)
		{

			close(fd);
		}
	}
	else
		exit(11);
	return (1);
}

