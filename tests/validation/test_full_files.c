//
// Created by alexey on 01.10.2020.
//

#include "tests.h"

static void	__test_valid_1__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 3
		&& data->links_nbr == 3
		&& ft_strequ(data->start_room, "0")
		&& ft_strequ(data->end_room, "1")
		&& (start = get_table(data->rooms, "0"))
		&& start->value.connections == 1
		&& (end = get_table(data->rooms, "1"))
		&& end->value.connections == 0
		&& (end = get_table(data->rooms, "3"))
		&& end->value.connections == 1)
			success();
		else
			fail();
	}
	else
		fail();
	remove_hashmap(data->rooms);
	ft_strdel(&data->start_room);
	ft_strdel(&data->end_room);
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void	__test_valid_2__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 2
			&& data->links_nbr == 5
			&& ft_strequ(data->start_room, "0")
			&& ft_strequ(data->end_room, "4")
			&& (start = get_table(data->rooms, "0"))
			&& start->value.connections == 2
			&& (end = get_table(data->rooms, "2"))
			&& end->value.connections == 1
			&& (end = get_table(data->rooms, "3"))
			&& end->value.connections == 1
			&& (end = get_table(data->rooms, "4"))
			&& end->value.connections == 1)
			success();
		else
			fail();
	}
	else
		fail();
	remove_hashmap(data->rooms);
	ft_strdel(&data->start_room);
	ft_strdel(&data->end_room);
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void	__test_valid_3__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 4
			&& data->links_nbr == 9
			&& ft_strequ(data->start_room, "start")
			&& ft_strequ(data->end_room, "end")
			&& (start = get_table(data->rooms, "start"))
			&& start->value.connections == 1
			&& (end = get_table(data->rooms, "3"))
			&& end->value.connections == 2
			&& (end = get_table(data->rooms, "2"))
			&& end->value.connections == 2
			&& (end = get_table(data->rooms, "1"))
			&& end->value.connections == 2
			&& (end = get_table(data->rooms, "6"))
			&& end->value.connections == 1
			&& (end = get_table(data->rooms, "end"))
			&& end->value.connections == 1)
			success();
		else
			fail();
	}
	else
		fail();
	remove_hashmap(data->rooms);
	ft_strdel(&data->start_room);
	ft_strdel(&data->end_room);
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

void		__FULL_FILES__(t_farm *data)
{
	printf("\nCheck valid files:\n");
	__test_valid_1__(data, 1, "valid_input/valid_1");
	__test_valid_2__(data, 2, "valid_input/valid_2");
	__test_valid_3__(data, 3, "valid_input/valid_3");
}