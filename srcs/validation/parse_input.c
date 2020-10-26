//
// Created by alexey on 28.09.2020.
//

#include "ant_farm.h"

static short 	count_max_paths(t_farm *data)
{
	int	*src;
	int	*sink

	src = ((t_room*)data->src->value)->nbr_arcs;
	sink = ((t_room*)data->sink->value)->nbr_arcs;
	data->max_paths = MIN(src, sink);
	data->err = data->paths.max != 0 ? data->err : ERR_PATH;
	return (data->paths.max);
}

static void	get_nbr_of_ants(t_farm *data, bool *is_ant_line)
{
	*is_ant_line = false;
	if (ft_ispositive_nbr(data->line)
		&& ft_strlen(data->line) < 11
		&& *(data->line) != '0')
		data->ants = ft_atoi(data->line);
	else
		data->err = ERR_ANT;
}

static void define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

static void	init_farm(t_farm *data)
{
	data->nbr_edges = 0;
	data->paths = NULL;
	data->start_room = NULL;
	data->end_room = NULL;
	data->err = -1;
	data->rooms = init_hashmap(TABLE_SIZE);
	IF_FAIL(data->rooms);
}

short 		parse_input(t_farm *data, short start_msg, short end_msg)
{
	bool	is_ant_line;

	is_ant_line = true;
	init_farm(data);
	while (data->err < 0 && get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start_msg, &end_msg);
		else if (is_ant_line)
			get_nbr_of_ants(data, &is_ant_line);
		else
			define_command(data, &start_msg, &end_msg);
		ft_strdel(&data->line);
	}
	return (data->err < 0 ? count_max_paths(data) : 0);
}