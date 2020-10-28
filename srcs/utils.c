//
// Created by alexey on 24.10.2020.
//

#include "ant_farm.h"

/*void 	print_path(t_hashmap *rooms, t_room *end)
{
	t_room *tmp;

	tmp = end;
	printf("%s", "H");
	while (tmp->member != NULL)
	{
		printf("<-%s", tmp->member);
		tmp = get_elem(rooms, tmp->member);
	}
	printf("\n");

}

void 	print_list(t_list *lst, char name[])
{
	t_connection *tmp;
	t_list		*cur;

	cur = lst;
	printf("%s  :", name);
	while (cur)
	{
		tmp = cur->content;
		printf("[%s %d]", tmp->room_name, tmp->flow);
		if (cur->next)
			printf(" -> ");
		cur = cur->next;
	}
	printf("\n\n");
}

void 	print_neighbors(t_hashmap *rooms)
{
	t_table *h;
	t_table *a;
	t_table *d;
	t_table *e;

	h = get_table(rooms, "H");
	a = get_table(rooms, "A");
	d = get_table(rooms, "D");
	e = get_table(rooms, "E");
	print_list(((t_room*)h->value)->neighbors, "H");
	print_list(((t_room*)a->value)->neighbors, "A");
	print_list(((t_room*)d->value)->neighbors, "D");
	print_list(((t_room*)e->value)->neighbors, "E");
}*/

static void 	del_value(void *val)
{
	t_room *room;

	room = val;
	if (room->route)
	{
		remove_queue(room->route->cur);
		ft_memdel((void**)&room->route);
	}
	if (room->neighbors)
		ft_lstclr(room->neighbors);
}

void 		clear_paths(t_path *paths)
{
	t_list	*to_del;
	t_list	*cur;

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

void 			clear_memory(t_farm *data)
{
	clear_paths(data->paths);
	remove_hashmap(data->rooms, del_value);
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