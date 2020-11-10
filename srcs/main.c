/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/10 10:33:54 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

int	main(void)
{
	t_farm		data;
	t_sdl		sdl[1];
	t_hashmap	*done;

	if (!parse_input(&data, STR_MSG, END_MSG))
		throw_error(data);
	init_sdl(sdl);
	find_solution(&data, MIN_STEPS);
	sdl->farm = &data;
	print_solution(data.paths, data.ants, ANTS_REACHED_TO_END, sdl);
	done = NULL;
	while (1)
	{
		draw_background(sdl, &data, done);
		sdl_events(sdl, &data, done);
	}
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	return (0);
}
