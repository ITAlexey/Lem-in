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
	while (get_next_line(data->fd, &data->line))
	{
		define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void*)g_path + BIAS, SIZE - BIAS);
}

static void __test_one_room__(t_farm *data, char *test_name, char *path, char const *key, char *flag)
{
	short start;
	short end;
	t_table *found;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if ((found = get_table(data->rooms, key)) != NULL)
	{
		if (flag == NULL)
			data->start_room == NULL ? success() : fail();
		else
		{
			ft_strequ(data->start_room, flag) ? success() : fail();
			ft_strdel(&data->start_room);
		}
		remove_hashmap(data->rooms);
	}
	else
		fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void *)g_path + BIAS, SIZE - BIAS);
}

static void	__test_several_rooms__(t_farm *data, char *test_name, char *path, char *keys[], char *flag)
{
	short start;
	short end;
	t_table *room_1;
	t_table *room_2;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err < 0
		&& (room_1 = get_table(data->rooms, keys[0])) != NULL
		&& (room_2 = get_table(data->rooms, keys[1])) != NULL
		&& ft_strequ(room_1->key, keys[0]) && ft_strequ(room_2->key, keys[1]))
	{
		if (flag == NULL)
			data->start_room == NULL ? success() : fail();
		else
		{
			ft_strequ(data->start_room, flag) ? success() : fail();
			ft_strdel(&data->start_room);
		}
	}
	else
		fail();
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void *)g_path + BIAS, SIZE - BIAS);
}

static void __test_all_rooms__(t_farm *data, char *test_name, char *path, char *keys[])
{
	short start;
	short end;
	t_table *plain_1;
	t_table *plain_2;
	t_table *start_1;
	t_table *plain_3;
	t_table *end_1;
	t_table *plain_4;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err < 0
		&& (plain_1 = get_table(data->rooms, keys[0])) != NULL
		&& (plain_2 = get_table(data->rooms, keys[1])) != NULL
		&& (start_1 = get_table(data->rooms, keys[2])) != NULL
		&& (plain_3 = get_table(data->rooms, keys[3])) != NULL
		&& (end_1 = get_table(data->rooms, keys[4])) != NULL
		&& (plain_4 = get_table(data->rooms, keys[5])) != NULL)
	{
		if (ft_strequ(data->start_room, start_1->key)
			   && ft_strequ(data->end_room, end_1->key))
		{
			ft_strdel(&data->start_room);
			ft_strdel(&data->end_room);
			success();
		}
		else
			fail();
	}
	else
		fail();
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void *)g_path + BIAS, SIZE - BIAS);
}

void 	__ROOMS__(t_farm *data)
{
	char *plains[] = {"plain1", "plain2"};
	char *starts[] = {"start1", "start2"};
	char *all[] = {"plain1", "plain2", "start1", "start2", "end1", "end2"};

	printf("\nCheck rooms:\n");
	__test_inv_room__(data, "Invalid coordinates", 3, ft_strcat(g_path,"room/wrong_coor"));
	__test_inv_room__(data, "Name that start with L", 3, ft_strcat(g_path,"room/invalid_name"));
	__test_one_room__(data, "Record one plain room","room/one_plain", "plain", NULL);
	__test_one_room__(data, "Record one start room", "room/one_start", "start", "start");

	__test_several_rooms__(data, "Record several plain room", "room/several_plain", plains, NULL);
	__test_several_rooms__(data, "Record several start rooms", "room/several_start", starts, "start1");
	__test_all_rooms__(data, "Record all rooms", "room/all_rooms", all);
}