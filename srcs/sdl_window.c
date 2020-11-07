/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:40:39 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/07 18:27:42 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

void	close_window(t_sdl *sdl, t_farm *data)
{
	clear_paths(data->paths);
	remove_hashmap(data->rooms);
	SDL_RenderClear(sdl->render);
	SDL_DestroyRenderer(sdl->render);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

void	init_sdl(t_sdl *sdl)
{
	TTF_Init();
	sdl->start = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("Error init_SDL\n");
		exit(1);
	}
	sdl->window = SDL_CreateWindow("Lem_in", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (!(sdl->window))
	{
		ft_putstr("Window Error\n");
		exit(1);
	}
	sdl->render = SDL_CreateRenderer(sdl->window, -1, 0);
	if (!sdl->render)
	{
		ft_putstr("Error Renderer\n");
		exit(1);
	}
	SDL_SetRenderDrawBlendMode(sdl->render, SDL_BLENDMODE_BLEND);
}
