/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:40:39 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/13 12:06:55 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	open_music(t_sdl *sdl)
{
	sdl->music = NULL;
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	sdl->music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(sdl->music, -1);
	sdl->delay = 1;
	sdl->ant_radius = 7;
	sdl->room_radius = 10;
	sdl->clear = 1;
}

void	close_window(t_sdl *sdl)
{
	Mix_CloseAudio();
	SDL_RenderClear(sdl->render);
	SDL_DestroyRenderer(sdl->render);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
	exit(0);
}

void	init_sdl(t_sdl *sdl)
{
	sdl->window = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("Error init_SDL\n");
		exit(1);
	}
	sdl->window = SDL_CreateWindow("Lem_in", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (!(sdl->window))
	{
		ft_putstr("Window Error\n");
		exit(1);
	}
	sdl->render = NULL;
	sdl->render = SDL_CreateRenderer(sdl->window, -1, 0);
	if (!sdl->render)
	{
		ft_putstr("Error Renderer\n");
		exit(1);
	}
	SDL_SetRenderDrawBlendMode(sdl->render, SDL_BLENDMODE_BLEND);
	open_music(sdl);
}
