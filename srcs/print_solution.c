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

static int		move_ants(t_hashmap **data, int ants, char *ant_name)
{
	int		nbr;
	t_table	*tmp;
	int		idx;

	nbr = 0;
	idx = 0;
	while (++idx < ants)
	{
		ant_name = ft_itoa(idx);
		IF_FAIL(ant_name);
		if ((tmp = get_elem(*data, ant_name)) != NULL)
		{
			tmp = ((t_room*)tmp->value)->route->cur->head->content;
			if (!((t_room*)tmp->value)->route && ++nbr)
				remove_elem(*data, ant_name);
			else
				IF_FAIL(put_elem(data, ant_name, tmp));
			ft_printf("L%d-%s ", idx, tmp->key);
		}
		free(ant_name);
	}
	return (nbr);
}

static t_list	*push_ant(t_hashmap **data, t_list *path, int id_ant)
{
	char	*ant_name;
	t_list	*node;
	t_table	*tmp;

	node = path->content;
	tmp = node->content;
	if (((t_room*)tmp->value)->route)
	{
		ant_name = ft_itoa(id_ant);
		IF_FAIL(ant_name);
		IF_FAIL(put_elem(data, ant_name, tmp));
		free(ant_name);
	}
	ft_printf("L%d-%s ", id_ant, tmp->key);
	return (path->next);
}

static bool		is_passed(int remain_ants, int *arr, int cur)
{
	int	result;
	int	idx;

	idx = 0;
	result = 0;
	while (idx < cur)
	{
		result += arr[cur] - arr[idx++];
		if (remain_ants <= result)
			return (false);
	}
	return (true);
}

void			print_solution(t_path *data, int ants, int reached)
{
	int			id_ant;
	t_hashmap	*output;
	t_list		*path;
	int			idx;

	id_ant = 1;
	output = init_hashmap(MAX_SIZE / 2, NULL);
	while (reached < ants)
	{
		idx = 0;
		path = data->all;
		reached += move_ants(&output, id_ant, NULL);
		while (path && id_ant <= ants)
		{
			if (is_passed(ants - id_ant + 1, data->lengths, idx++))
				path = push_ant(&output, path, id_ant++);
			else
				break ;
		}
		ft_putchar('\n');
	}
	remove_hashmap(output);
}
