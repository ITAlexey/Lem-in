//
// Created by alexey on 24.10.2020.
//

#include "ant_farm.h"

void 	print_path(t_path *paths)
{
	t_list	*path;
	t_list	*node;
	t_table	*tmp;

	path = paths->all;
	while (path)
	{
		node = path->content;
		while (node)
		{
			tmp = node->content;
			printf("[%s]->", tmp->key);
			node = node->next;
		}
		printf("\n");
		path = path->next;
	}
}

void 	del_value(void *val)
{
	t_room *room;

	room = val;
	if (room->route)
	{
		remove_queue(room->route->cur);
		room->route->new ? remove_queue(room->route->new) : 0;
		ft_memdel((void**)&room->route);
	}
	if (room->neighbors)
		ft_lstclr(room->neighbors);
}

void 		clear_paths(t_path *paths)
{
	t_list	*to_del;
	t_list	*cur;

	if (paths)
	{
		cur = paths->all;
		while (cur)
		{
			to_del = cur;
			ft_lstclr((t_list*)cur->content);
			cur = cur->next;
			free(to_del);
		}
		to_del = NULL;
		ft_memdel((void**)&paths->lengths);
		ft_memdel((void**)&paths);
	}
}

static void 	init_errors(char *err_lst[])
{
	err_lst[0] = "Invalid number of ants.";
	err_lst[1] = "Multiple start or end commands.";
	err_lst[2] = "Invalid format line.";
	err_lst[3] = "Invalid format of room name or coordinates.";
	err_lst[4] = "Absent destination room.";
	err_lst[5] = "Absent origin room.";
	err_lst[6] = "Non-existent room name.";
	err_lst[7] = "Empty lines are forbidden.";
	err_lst[8] = "Paths are not exist.";
}

void 	throw_error(t_farm data)
{
	char 	*errors[ERRORS];

	init_errors(errors);
	ft_printf("ERROR: %s\n", errors[data.err]);
	exit(EXIT_FAILURE);
}