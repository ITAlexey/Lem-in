//
// Created by alexey on 28.09.2020.
//

#include "ant_farm.h"

void get_nbr_of_ants(t_farm *data)
{
	if (get_next_line(data->fd, &data->line)
		&& ft_ispositive_nbr(data->line)
		&& ft_strlen(data->line) > 0
		&& ft_strlen(data->line) < 11
		&& *(data->line) != '0')
		data->ants = ft_atoi(data->line);
	else
		data->is_err = ERR_ANT;
	ft_strdel(&data->line);
}

void define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->is_err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

static void	init_farm(t_farm *data)
{
	data->links_nbr = 0;
	ft_bzero(&data->room_type, sizeof(t_typeroom));
	data->is_err = -1;
	data->err_lst[0] = "Invalid number of ants.";
	data->err_lst[1] = "Multiple start or end commands.";
	data->err_lst[2] = "Invalid format line.";
	data->err_lst[3] = "Invalid format of room name or coordinates.";
	data->err_lst[4] = "Absent destination rooms.";
	data->err_lst[5] = "Absent origin rooms.";
	data->err_lst[6] = "Non-existent room name.";
	data->err_lst[7] = "Empty lines are forbidden.";
}

void 		parse_input(t_farm *data)
{
	short 	start_msg;
	short 	end_msg;

	start_msg = 0;
	end_msg = 0;
	init_farm(data);
	get_nbr_of_ants(data);
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->is_err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start_msg, &end_msg);
		else
			define_command(data, &start_msg, &end_msg);
		ft_strdel(&data->line);
	}
	if (data->is_err >= 0)
	{
		ft_printf("ERROR: %s\n", data->err_lst[data->is_err]);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("SUCCESS\n");
}