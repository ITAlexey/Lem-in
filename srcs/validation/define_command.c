//
// Created by alexey on 01.10.2020.
//

#include "ant_farm.h"

static void 	record_room(t_hashmap **room_type, char **room_data, int *size)
{
	t_value	value;

	value.x = ft_atoi(room_data[1]);
	value.y = ft_atoi(room_data[2]);
	value.connections = 0;
	if (*size == 0)
	{
		*room_type = init_hashmap(TABLE_SIZE);
		IF_FAIL(*room_type);
	}
	(*size)++;
	IF_FAIL(put_elem(room_type, create_table(room_data[0], &value)));
}

static void 	define_type(t_typeroom *type, char **room_data, short *start, short *end)
{
	if (*start && *end)
		record_room(&type->end, room_data, &type->end_size);
	else if (*start)
		record_room(&type->start, room_data, &type->start_size);
	else
		record_room(&type->plain, room_data, &type->plain_size);
}

static void 	define_room(t_farm *data, short *start, short *end)
{
	char 	**data_room;

	data_room = ft_strsplit(data->line, ' ');
	IF_FAIL(data_room);
	if (*(data_room[0]) != 'L'
		&& ft_ispositive_nbr(data_room[1])
		&& ft_ispositive_nbr(data_room[2]))
		define_type(&data->room_type, data_room, start, end);
	else
		data->is_err = ERR_ROOM;
	ft_free2darray((void**)data_room);
}

void 		define_command(t_farm *data, short *start, short *end)
{
	if (!data->links_nbr && ft_count_words(data->line, ' ') == 3)
		define_room(data, start, end);
	else if (ft_count_words(data->line, '-') == 2)
		define_link(data);
	else
		data->is_err = ERR_FRT;
}