/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/06 13:02:01 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static short	count_max_paths(t_farm *data)
{
	int	src;
	int	sink;

	src = ((t_room*)data->src->value)->nbr_arcs;
	sink = ((t_room*)data->sink->value)->nbr_arcs;
	data->max_paths = MIN(src, sink);
	data->err = data->max_paths != 0 ? data->err : ERR_PATH;
	return (data->max_paths);
}

static void		get_nbr_of_ants(t_farm *data)
{
	if (ft_ispositive_nbr(data->line)
		&& ft_strlen(data->line) < 11
		&& *(data->line) != '0')
		data->ants = ft_atoi(data->line);
	else
		data->err = ERR_ANT;
}

static void		define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

static void		init_farm(t_farm *data)
{
	data->ants = 0;
	data->nbr_edges = 0;
	data->paths = NULL;
	data->src = NULL;
	data->sink = NULL;
	data->err = -1;
	data->rooms = init_hashmap(TABLE_SIZE, del_value);
	data->pos = 0;
	for (int i = 0; i < 200; i++)
		data->vis[i] = NULL;
	IF_FAIL(data->rooms);
}

short			parse_input(t_farm *data, short start_msg, short end_msg)
{
	init_farm(data);
	while (data->err < 0 && get_next_line(STDIN, &data->line))
	{
		if (!ft_strlen(data->line))
			data->err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start_msg, &end_msg);
		else if (!data->ants)
			get_nbr_of_ants(data);
		else
			define_command(data, &start_msg, &end_msg);
		ft_strdel(&data->line);
	}
	return (data->err < 0 ? count_max_paths(data) : 0);
}
