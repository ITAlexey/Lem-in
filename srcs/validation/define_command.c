//
// Created by alexey on 01.10.2020.
//

#include "ant_farm.h"

void 	fill_room(t_room *room, int x, int y)
{
	room->x = x;
	room->y = y;
	room->is_visited = false;
	room->nbr_arcs = 0;
	room->capacity = 1;
	room->flow = 0;
}

void 	record_room(t_farm *data, char **room_data, short *start, short *end)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	IF_FAIL(room);
	fill_room(room, ft_atoi(room_data[1]), ft_atoi(room_data[2]));
	if (*start && !data->start_room)
	{
		data->start_room = ft_strdup(room_data[0]);
		room->id = 0;
	}
	else if (*end && !data->end_room)
		data->end_room = ft_strdup(room_data[0]);
	else
		room->id = data->nbr_rooms;
	IF_FAIL(put_elem(&data->rooms,
	 		create_table(room_data[0], (void*)room, sizeof(t_room))));
}

static void 	define_room(t_farm *data, short *start, short *end)
{
	char 	**data_room;

	data_room = ft_strsplit(data->line, ' ');
	IF_FAIL(data_room);
	if (*(data_room[0]) != 'L'
		&& ft_ispositive_nbr(data_room[1])
		&& ft_ispositive_nbr(data_room[2]))
	{
		data->nbr_rooms++;
		record_room(data, data_room, start, end);
	}
	else
		data->is_err = ERR_ROOM;
	ft_free2darray((void**)data_room);
}

void 		define_command(t_farm *data, short *start, short *end)
{
	t_table	*end_room;

	if (!data->nbr_edges && ft_count_words(data->line, ' ') == 3)
		define_room(data, start, end);
	else if (ft_count_words(data->line, '-') == 2)
	{
		end_room = get_table(data->rooms, data->end_room);
		((t_room*)end_room->value)->id = data->nbr_rooms - 1;
		define_link(data);
	}
	else
		data->is_err = ERR_FRT;
}