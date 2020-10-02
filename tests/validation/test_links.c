//
// Created by alexey on 01.10.2020.
//

#include "tests.h"

static void	__test_inv_link__(t_farm *data, char *test_name, char *path, int err_code)
{
	short start;
	short end;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void __test_one_link__(t_farm *data, char *test_name, char *path)
{
	short start;
	short end;
	t_table *node;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->is_err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err < 0)
	{
		if ((node = get_table(data->rooms, "0")) != NULL)
		{
			if (node->value.connections == 1 && ft_strequ(((t_table*)node->value.links->content)->key, "1"))
			{
				success();
				ft_strdel(&data->start_room);
				ft_strdel(&data->end_room);
			}
			else
				fail();
		}
	}
	else
		fail();
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void __test_several_links__(t_farm *data, char *test_name, char *path)
{
	short start;
	short end;
	t_table *node_1;
	t_table *node_2;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->is_err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err < 0)
	{
		if ((node_1 = get_table(data->rooms, "1")) != NULL
			&& (node_2 = get_table(data->rooms, "2")) != NULL)
		{
			if (ft_strequ(((t_table*)node_1->value.links->content)->key, "2")
				&& ft_strequ(((t_table*)node_2->value.links->content)->key, "3")
				&& ft_strequ(((t_table*)node_2->value.links->next->content)->key, "4"))
			{
				success();
				ft_strdel(&data->start_room);
				ft_strdel(&data->end_room);
			}
			else
				fail();
		}
	}
	else
		fail();
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

static void	__test_non_existent_name__(t_farm *data, char *test_name, char *path, int err_code)
{
	short start;
	short end;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(ft_strcat(g_path, path), O_RDONLY);
	init_farm(data);
	while (get_next_line(data->fd, &data->line))
	{
		if (!ft_strlen(data->line))
			data->is_err = ERR_NL;
		else if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	ft_strdel(&data->start_room);
	ft_strdel(&data->end_room);
	remove_hashmap(data->rooms);
	data->is_err = -1;
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

void 	__LINKS__(t_farm *data)
{
	printf("\nCheck links:\n");
	__test_inv_link__(data, "Passes only links", "links/only_links", 4);
	__test_one_link__(data, "One valid link", "links/put_one_link");
	__test_several_links__(data, "Several valid links", "links/put_several_links");
	__test_non_existent_name__(data, "Passes only links", "links/non-existent_name_1", 6);
	__test_non_existent_name__(data, "Passes only links", "links/non-existent_name_2", 6);
}