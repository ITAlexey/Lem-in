//
// Created by alexey on 28.09.2020.
//

#include "ant_farm.h"

short 		ft_ispos_str_of_digits(char const *str)
{
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

void 		get_nbr_of_ants(t_farm *data)
{
	if (get_next_line(data->fd, &data->line) >= 0
		&& ft_ispos_str_of_digits(data->line)
		&& ft_strlen(data->line) < 11)
		data->ants = ft_atoi(data->line);
	else
		data->is_err = ERR_ANT;
	ft_strdel(&data->line);
}

void 		define_comment(t_farm *data, short *start, short *end)
{
	if (!ft_strcmp("##start", data->line))
		(*start)++;
	else if (!ft_strcmp("##end", data->line))
		(*end)++;
	data->is_err = *start > 1 || *end > 1 ? ERR_CMD : -1;
}

void 		record_room(t_hashmap *room_type, char **room_data, int *size)
{
	t_value	*value;

	value = (t_value*)ft_memalloc(sizeof(t_value));
	IF_FAIL(value);
	if (*size == 0)
	{
		room_type = init_hashmap(TABLE_SIZE);
		IF_FAIL(room_type);
	}
	(*size)++;
	IF_FAIL(put_elem(&room_type, create_table(room_data[0], value)));
}

void 		define_type(t_farm *data, char **room_data, short *start, short *end)
{
	if (*start && *end)
		record_room(data->room_type.end , room_data, &data->room_type.end_size);
	else if (*start)
		record_room(data->room_type.start , room_data, &data->room_type.start_size);
	else
		record_room(data->room_type.plain , room_data, &data->room_type.plain_size);
}

void 		define_room(t_farm *data, short *start, short *end)
{
	char 	**data_room;

	data_room = ft_strsplit(data->line, ' ');
	IF_FAIL(data_room);
	if (*(data_room[0]) != 'L'
		&& ft_ispos_str_of_digits(data_room[1])
		&& ft_ispos_str_of_digits(data_room[2]))
		define_type(data, data_room, start, end);
	else
		data->is_err = ERR_ROOM;
	ft_free2darray((void**)data_room);
}

t_table		*is_room_exist(t_typeroom types, char *key)
{
	t_table *table;

	if ((table = get_table(types.start, key)) != NULL)
		return (table);
	else if ((table = get_table(types.end, key)) != NULL)
		return (table);
	else if (types.plain_size && (table = get_table(types.plain, key)) != NULL)
		return (table);
	return (NULL);
}

void 		record_link(t_table *table, char *link_room)
{
	//table->value.links;
}

void 		define_link(t_farm *data)
{
	char 		**data_link;
	t_table		*table;

	if (!data->room_type.start_size || !data->room_type.end_size)
		data->is_err = !data->room_type.end_size ? ERR_END : ERR_START;
	else
	{
		data_link = ft_strsplit(data->line, '-');
		IF_FAIL(data_link);
		if ((table = is_room_exist(data->room_type, data_link[0])) != NULL
			&& is_room_exist(data->room_type, data_link[1]))
		{
			data->links_nbr++;
			record_link(table, data_link[1]);
		}
		else
			data->is_err = ERR_LINK;
		ft_free2darray((void**)data_link);
	}
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

static void 	init_error_list(char *err_lst[])
{
	err_lst[0] = "Invalid number of ants.";
	err_lst[1] = "Multiple start or end commands.";
	err_lst[2] = "Invalid format line.";
	err_lst[3] = "Invalid format of room name or coordinates.";
	err_lst[4] = "Absent destination rooms.";
	err_lst[5] = "Absent origin rooms.";
	err_lst[6] = " Name of room has not been found.";
	//err_lst[7] = "";

}

void 		parse_input(t_farm *data)
{
	short 	start_msg;
	short 	end_msg;

	start_msg = 0;
	end_msg = 0;
	init_error_list(data->err_lst);
	get_nbr_of_ants(data);
	while (data->is_err < 0 && get_next_line(data->fd, &data->line) >= 0)
	{
		if (*(data->line) == '#')
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