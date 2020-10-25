//
// Created by alexey on 28.09.2020.
//

#include "ant_farm.h"

void	get_nbr_of_ants(t_farm *data)
{
	if (ft_ispositive_nbr(data->line)
		&& ft_strlen(data->line) < 11
		&& *(data->line) != '0')
		data->ants = ft_atoi(data->line);
	else
		data->err = ERR_ANT;
}

void define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

void	init_farm(t_farm *data)
{
	data->nbr_edges = 0;
	data->start_room = NULL;
	data->end_room = NULL;
	data->err = -1;
	data->paths.found = 0;
	data->rooms = init_hashmap(TABLE_SIZE);
	IF_FAIL(data->rooms);
}

int 		parse_input(t_farm *data)
{
	short 	start_msg;
	short 	end_msg;
	bool	is_ant_line;

	is_ant_line = true;
	start_msg = 0;
	end_msg = 0;
	init_farm(data);
	while (data->err < 0 && get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start_msg, &end_msg);
		else if (is_ant_line)
		{
			get_nbr_of_ants(data);
			is_ant_line = false;
		}
		else
			define_command(data, &start_msg, &end_msg);
		ft_strdel(&data->line);
	}
	return (data->err < 0);
}