//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

static void __test_inv_room__(t_farm *data, char *test_name, int err_code, char *path)
{
	short start;
	short end;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(path, O_RDONLY);
	data->links_nbr = 0;
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void*)g_path + BIAS, SIZE - BIAS);
}

static void __test_one_room__(t_farm *data, char *test_name, char *path, char const *key, t_hashmap **type)
{
	short start;
	short end;
	t_table *found;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	data->links_nbr = 0;
	data->room_type.start_size = 0;
	data->room_type.plain_size = 0;
	data->room_type.end_size = 0;
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if ((found = get_table(*type, key)) != NULL)
	{
		remove_elem(*type, key);
		if (get_table(*type, key) == NULL)
			success();
		else
			fail();
		remove_hashmap(*type);
	}
	else
		fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void *)g_path + BIAS, SIZE - BIAS);
}

static void	__test_several_rooms__(t_farm *data, char *test_name, char *path, char *keys[], t_hashmap **type)
{
	short start;
	short end;
	t_table *plain_1;
	t_table *plain_2;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	data->links_nbr = 0;
	data->room_type.start_size = 0;
	data->room_type.plain_size = 0;
	data->room_type.end_size = 0;
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err < 0
		&& (plain_1 = get_table(*type, keys[0])) != NULL
		&& (plain_2 = get_table(*type, keys[1])) != NULL)
	{
		remove_elem(*type, keys[0]);
		remove_elem(*type, keys[1]);
		if (!get_table(*type, keys[0]) && !get_table(*type, keys[1]))
			success();
		else
			fail();
		remove_hashmap(*type);
	}
	else
		fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void *)g_path + BIAS, SIZE - BIAS);
}

void 	__ROOMS__(t_farm *data)
{
	char *plains[] = {"plain1", "plain2"};
	char *starts[] = {"start1", "start2"};

	printf("\nCheck rooms:\n");
	__test_inv_room__(data, "Invalid coordinates", 3, ft_strcat(g_path,"room/wrong_coor"));
	__test_inv_room__(data, "Name that start with L", 3, ft_strcat(g_path,"room/invalid_name"));

	__test_one_room__(data, "Record one plain room","room/one_plain", "plain", &data->room_type.plain);
	__test_one_room__(data, "Record one start room", "room/one_start", "start", &data->room_type.start);

	__test_several_rooms__(data, "Record several plain room", "room/several_plain", plains, &data->room_type.plain);
	__test_several_rooms__(data, "Record several start rooms", "room/several_start", starts, &data->room_type.start);
	//__test_all_rooms__(data, "Record several plain, start and end rooms", -1, "tests/txt/room/", 6);
}