/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/06 11:23:35 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static t_room	*init_room(int x, int y)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	IF_FAIL(room);
	room->x = x;
	room->y = y;
	room->nbr_arcs = 0;
	room->in = NULL;
	room->member = NULL;
	room->route = NULL;
	room->neighbors = NULL;
	room->is_dup = 0;
	return (room);
}

void			record_room(t_farm *data, char **room_data,
					short *start, short *end)
{
	t_room	*room;

	room = init_room(ft_atoi(room_data[1]), ft_atoi(room_data[2]));
	IF_FAIL(put_elem(&data->rooms, room_data[0], (void*)room));
	if (*start && !data->src)
		data->src = get_table(data->rooms, room_data[0]);
	else if (*end && !data->sink)
		data->sink = get_table(data->rooms, room_data[0]);
}

static void		define_room(t_farm *data, short *start, short *end)
{
	char	**data_room;

	data_room = ft_strsplit(data->line, ' ');
	IF_FAIL(data_room);
	if (*(data_room[0]) != 'L'
			&& ft_ispositive_nbr(data_room[1])
			&& ft_ispositive_nbr(data_room[2])
			&& !get_table(data->rooms, data_room[0]))
		record_room(data, data_room, start, end);
	else
		data->err = get_table(data->rooms, data_room[0]) ? ERR_DUP : ERR_ROOM;
	ft_free2darray((void**)data_room);
}

void			define_command(t_farm *data, short *start, short *end)
{
	if (!data->nbr_edges && ft_count_words(data->line, ' ') == 3)
		define_room(data, start, end);
	else if (ft_count_words(data->line, '-') == 2)
		define_link(data);
	else
		data->err = ERR_FRT;
}
