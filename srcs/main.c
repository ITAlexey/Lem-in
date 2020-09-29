//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"

int 	main(void)
{
	t_farm		data;

	if ((data.fd = open(INPUT, O_RDONLY)) > 0)
	{
		data.is_err = -1;
		parse_input(&data);
		close(data.fd);
	}
	else
	{
		ft_printf("ERROR.");
		exit(EXIT_FAILURE);
	}
	return (0);
}

