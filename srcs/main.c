/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/07 19:19:59 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

int	main(void)
{
	t_farm		data;
	t_sdl		sdl[1];

	if (!parse_input(&data, STR_MSG, END_MSG))
		throw_error(data);
	init_sdl(sdl);
	Mix_Init(MIX_INIT_MP3);//AUDIO
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Music *pahomsong = NULL;
	pahomsong=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(pahomsong, -1);
	find_solution(&data, MIN_STEPS);
	sdl->farm = &data;
	print_solution(data.paths, data.ants, ANTS_REACHED_TO_END, sdl);
	while (1)
	{
		draw_background(sdl, &data);
		sdl_events(sdl, &data);
	}
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	return (0);
}
