/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/11 18:14:01 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

int	main(int ac, char *av[])
{
	t_farm		data;

	if (!parse_input(&data, STR_MSG, END_MSG))
		throw_error(data);
	find_solution(&data, MIN_STEPS);
	print_solution(data.paths, data.ants, ANTS_REACHED_TO_END);
	if (ac == 3 && ft_strequ("-v", av[1]))
	{
		data.arr = cast_to_array(data.rooms);
		IF_FAIL(data.arr);
		visualisation(data, av[2]);
	}
	ft_memdel((void**)&data.arr);
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	return (0);
}
