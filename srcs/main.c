//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"
#include <stdio.h>

short 	is_equal(void *a, void *b)
{
	char			*str;
	t_connection	*link;

	link = (t_connection*)a;
	str = (char*)b;
	return ((short)ft_strequ(str, link->room_name));
}

void 	redirection(t_hashmap *rooms, t_table *end)
{
	t_list			*link;
	t_table			*tmp;
	t_room			*next_room;
	char 			*parent_name;

	tmp = end;
	next_room = tmp->value;
	while (next_room->member)
	{
		parent_name = (char*)tmp->key;
		link = ft_lstfind(next_room->neighbors, (void*)next_room->member, is_equal);
		((t_connection*)link->content)->flow = -1;
		tmp = get_table(rooms, next_room->member);
		next_room = tmp->value;
		ft_lstremove(&next_room->neighbors, (void*)parent_name, is_equal);
		next_room->nbr_arcs--;
	}

}

void 	print_path(t_hashmap *rooms, t_room *end)
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

short 	find_paths(t_farm *data)
{
	t_room	*start;
	t_room	*end;

	start = get_elem(data->rooms, data->start_room);
	end = get_elem(data->rooms, data->end_room);
	data->max_nbr_paths = MIN(start->nbr_arcs, end->nbr_arcs);
	data->err = data->max_nbr_paths != 0 ? data->err : ERR_PATH;
	if (data->err != -1 || bfs(data) == NULL)
		data->err = ERR_PATH;
	return (data->err);
}

//void 	print_neighbors(t_hashmap *rooms)

int 	main(void)
{
	t_farm		data;

	if ((data.fd = open(INPUT, O_RDONLY)) > 0)
	{
		if (parse_input(&data) >= 0
			|| find_paths(&data) >= 0)
		{
			ft_printf("ERROR: %s\n", data.err_lst[data.err]);
			exit(EXIT_FAILURE);
		}
		close(data.fd);
	}
	else
	{
		ft_printf("ERROR.");
		exit(EXIT_FAILURE);
	}
	redirection(data.rooms, get_table(data.rooms, data.end_room));
	print_path(data.rooms, (t_room*)get_elem(data.rooms, data.end_room));
	//print_neighbors(data.rooms);
	return (0);
}

