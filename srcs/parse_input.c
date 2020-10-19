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
		data->is_err = ERR_ANT;
}

void define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->is_err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

void	init_farm(t_farm *data)
{
	data->nbr_edges = 0;
	data->nbr_rooms = 0;
	data->start_room = NULL;
	data->end_room = NULL;
	data->is_err = -1;
	data->rooms = init_hashmap(TABLE_SIZE);
	IF_FAIL(data->rooms);
	data->err_lst[0] = "Invalid number of ants.";
	data->err_lst[1] = "Multiple start or end commands.";
	data->err_lst[2] = "Invalid format line.";
	data->err_lst[3] = "Invalid format of room name or coordinates.";
	data->err_lst[4] = "Absent destination rooms.";
	data->err_lst[5] = "Absent origin rooms.";
	data->err_lst[6] = "Non-existent room name.";
	data->err_lst[7] = "Empty lines are forbidden.";
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
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->is_err = ERR_NL;
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
	return (data->is_err);
}