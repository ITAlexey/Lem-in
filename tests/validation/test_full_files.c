//
// Created by alexey on 01.10.2020.
//

#include "tests.h"

static void	__test_valid_1__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end_1;
	t_table *end_2;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 3
		&& data->links_nbr == 3
		&& (start = get_table(data->room_type.start, "0"))
		&& start->value.connections == 1
		&& (end_1 = get_table(data->room_type.end, "2"))
		&& end_1->value.connections == 1
		&& (end_2 = get_table(data->room_type.end, "3"))
		&& end_2->value.connections == 1)
			success();
		else
			fail();
		remove_hashmap(data->room_type.start);
		remove_hashmap(data->room_type.end);
	}
	else
		fail();
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void	__test_valid_2__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end_1;
	t_table *end_2;
	t_table *end_3;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 2
			&& data->links_nbr == 5
			&& (start = get_table(data->room_type.start, "0"))
			&& start->value.connections == 2
			&& (end_1 = get_table(data->room_type.end, "2"))
			&& end_1->value.connections == 1
			&& (end_2 = get_table(data->room_type.end, "3"))
			&& end_2->value.connections == 1
			&& (end_3 = get_table(data->room_type.end, "4"))
			&& end_3->value.connections == 1)
			success();
		else
			fail();
		remove_hashmap(data->room_type.start);
		remove_hashmap(data->room_type.end);
		remove_hashmap(data->room_type.plain);
	}
	else
		fail();
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void	__test_valid_3__(t_farm *data, int nbr_file, char *path)
{
	t_table *start;
	t_table *end_1;
	t_table *end_2;
	t_table *end_3;
	t_table *end_4;
	t_table *plain;

	printf("Test: Valid file number %-17d", nbr_file);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	if (parse_input(data) == -1)
	{
		if (data->ants == 4
			&& data->links_nbr == 9
			&& (start = get_table(data->room_type.start, "start"))
			&& start->value.connections == 1
			&& (plain = get_table(data->room_type.plain, "3"))
			&& plain->value.connections == 2
			&& (end_1 = get_table(data->room_type.end, "2"))
			&& end_1->value.connections == 2
			&& (end_2 = get_table(data->room_type.end, "1"))
			&& end_2->value.connections == 2
			&& (end_3 = get_table(data->room_type.end, "6"))
			&& end_3->value.connections == 1
			&& (end_4 = get_table(data->room_type.end, "end"))
			&& end_4->value.connections == 1)
			success();
		else
			fail();
		remove_hashmap(data->room_type.start);
		remove_hashmap(data->room_type.end);
		remove_hashmap(data->room_type.plain);
	}
	else
		fail();
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