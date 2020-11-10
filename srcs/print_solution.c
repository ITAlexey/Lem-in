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

int		move_ant(t_hashmap **data, int reached, int ants, t_sdl *sdl)
{
	int		nbr;
	char	*ant_name;
	t_table	*tmp;

	nbr = 0;
	while (reached < ants)
	{
		ant_name = ft_itoa(reached);
		IF_FAIL(ant_name);
		tmp = get_elem(*data, ant_name);
		tmp = ((t_room*)tmp->value)->route->cur->head->content;
		if (!((t_room*)tmp->value)->route)
			nbr++;
		else
			IF_FAIL(put_elem(data, ant_name, tmp));
		if (sdl->farm->visual)
			note_movements(sdl, reached, tmp->key);
		ft_printf("L%d-%s ", reached++, tmp->key);
		free(ant_name);
	}
	return (nbr);
}

int		push_ant(t_hashmap **data, t_table *node, int id_ant, t_sdl *sdl)
{
	char	*ant_name;
	int		nbr;

	nbr = 0;
	if (((t_room*)node->value)->route)
	{
		ant_name = ft_itoa(id_ant);
		IF_FAIL(ant_name);
		IF_FAIL(put_elem(data, ant_name, node));
		free(ant_name);
	}
	else
		nbr++;
	if (sdl->farm->visual)
		note_movements(sdl, id_ant, node->key);
	ft_printf("L%d-%s ", id_ant, node->key);
	return (nbr);
}

void	print_solution(t_path *data, int ants, int reached, t_sdl *sdl)
{
	int			id_ant;
	t_hashmap	*output;
	t_list		*path;
	t_list		*node;

	id_ant = 1;
	output = init_hashmap(MAX_SIZE / 3, NULL);
	if (sdl->farm->visual)
		fill_ants(sdl, sdl->farm);
	while (reached < ants)
	{
		path = data->all;
		reached += move_ant(&output, reached + 1, id_ant, sdl);
		while (path && id_ant <= ants)
		{
			node = path->content;
			reached += push_ant(&output, (t_table*)node->content,
												id_ant++, sdl);
			path = path->next;
		}
		if (sdl->farm->visual)
			draw_movements(sdl, sdl->farm, output);
		ft_putchar('\n');
	}
	remove_hashmap(output);
}
