//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"

int 	main(void)
{
	t_farm		data;

	if ((data.fd = open(INPUT, O_RDONLY)) > 0)
	{
		if (parse_input(&data) != -1)
		{
			ft_printf("ERROR: %s\n", data->err_lst[data->is_err]);
			exit(EXIT_FAILURE);
		}
		close(data.fd);
	}
	else
	{
		ft_printf("ERROR.");
		exit(EXIT_FAILURE);
	}
	return (0);
}

