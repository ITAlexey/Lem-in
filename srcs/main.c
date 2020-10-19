//
// Created by alexey on 22.09.2020.
//

#include "ant_farm.h"
#include <stdio.h>

void 	iterate_and_print(t_list *lst)
{
	t_connection	*c;

	while (lst)
	{
		c = (t_connection*)lst->content;
		printf("name: %s, capacity: %d, flow %d\n", c->room_name, c->capacity, c->flow);
		lst = lst->next;
	}
}

void 	print_links(t_farm d)
{
	t_room *start;
	t_room	*end;
	t_room	*first;

	end = (t_room*)get_elem(d.rooms, d.end_room);
	start = (t_room*)get_elem(d.rooms, d.start_room);
	first = (t_room*)get_elem(d.rooms, "1");
	printf("START LINKS:\n");
	iterate_and_print(start->neighbors);
	printf("END LINKS:\n");
	iterate_and_print(end->neighbors);
	printf("FIRST ROOM:\n");
	iterate_and_print(first->neighbors);
}

int 	main(void)
{
	t_farm		data;

	if ((data.fd = open(INPUT, O_RDONLY)) > 0)
	{
		if (parse_input(&data) != -1)
		{
			ft_printf("ERROR: %s\n", data.err_lst[data.is_err]);
			exit(EXIT_FAILURE);
		}
		close(data.fd);
	}
	else
	{
		ft_printf("ERROR.");
		exit(EXIT_FAILURE);
	}
	print_links(data);
	return (0);
}

