/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/10 12:49:35 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

int		move_ant(t_hashmap **data, int ants, char *ant_name)
{
	int		nbr;
	t_table	*tmp;
	int 	idx;

	nbr = 0;
	idx = 1;
	while (idx < ants)
	{
		ant_name = ft_itoa(idx);
		IF_FAIL(ant_name);
		if ((tmp = get_elem(*data, ant_name)) != NULL)
		{
			tmp = ((t_room*)tmp->value)->route->cur->head->content;
			if (!((t_room*)tmp->value)->route)
			{
				//remove_elem(*data, ant_name);
				nbr++;
			}
			else
				IF_FAIL(put_elem(data, ant_name, tmp));
			ft_printf("L%d-%s ", idx++, tmp->key);
		}
		free(ant_name);
	}
	return (nbr);
}

void		push_ant(t_hashmap **data, t_table *node, int id_ant)
{
	char	*ant_name;

	if (((t_room*)node->value)->route)
	{
		ant_name = ft_itoa(id_ant);
		IF_FAIL(ant_name);
		IF_FAIL(put_elem(data, ant_name, node));
		free(ant_name);
	}
	ft_printf("L%d-%s ", id_ant, node->key);
}

void print_hm(t_hashmap *output)
{
	ft_putstr("\n===hashmap===\n");
	for (int i = 0; i < output->size; i++)
	{
		t_list *cur;
		cur = &output->arr[i];
		ft_printf("%d\t", i);
		while (cur)
		{
			if (cur->content_size != 0)
				ft_printf("[%s]->", ((t_table*)cur->content)->key);
			else
				ft_putstr("[-]");
			cur = cur->next;
		}
		ft_putchar('\n');
	}
}

void	print_solution(t_path *data, int ants, int reached)
{
	int			id_ant;
	t_hashmap	*output;
	t_list		*path;
	t_list		*node;

	id_ant = 1;
	output = init_hashmap(15, NULL);
	while (reached < ants)
	{
		path = data->all;
		reached += move_ant(&output, id_ant, NULL);
		while (path && id_ant <= ants)
		{
			node = path->content;
			push_ant(&output, (t_table*)node->content, id_ant++);
			path = path->next;
		}
		ft_putchar('\n');
	}
	//print_hm(output);
	remove_hashmap(output);
}
