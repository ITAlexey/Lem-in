//
// Created by alexey on 01.11.2020.
//

#include "ant_farm.h"

int 	move_ant(t_hashmap *data, int reached, int ants)
{
	int		nbr;
	char 	*ant_name;
	t_table	*tmp;

	nbr = 0;
	while (reached < ants)
	{
		ant_name = ft_itoa(reached);
		IF_FAIL(ant_name);
		tmp = get_elem(data, ant_name);
		tmp = ((t_room*)tmp->value)->route->cur->head->content;
		if (!((t_room*)tmp->value)->route)
		{
			nbr++;
			remove_elem(data, ant_name);
		}
		else
			IF_FAIL(put_elem(&data, ant_name, tmp, sizeof(t_table)));
		ft_printf("L%d-%s ", reached++, tmp->key);
		free(ant_name);
	}
	return (nbr);
}

int 	push_ant(t_hashmap *data, t_table *node, int id_ant)
{
	char 	*ant_name;
	int 	nbr;

	nbr = 0;
	if (((t_room*)node->value)->route)
	{
		ant_name = ft_itoa(id_ant);
		IF_FAIL(ant_name);
		IF_FAIL(put_elem(&data, ant_name, node, sizeof(t_table)));
		free(ant_name);
	}
	else
		nbr++;
	ft_printf("L%d-%s ", id_ant, node->key);
	return (nbr);
}

void 	print_solution(t_path *data, int ants, int reached)
{
	int 		id_ant;
	t_hashmap	*output;
	t_list		*path;
	t_list		*node;

	id_ant = 1;
	output = init_hashmap(100, NULL);
	while (reached < ants)
	{
		path = data->all;
		reached += move_ant(output, reached + 1, id_ant);
		while (path && id_ant <= ants)
		{
			node = path->content;
			reached += push_ant(output, (t_table*)node->content, id_ant++);
			path = path->next;
		}
		ft_putchar('\n');
	}
	remove_hashmap(output);
}