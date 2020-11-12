/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:12:51 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/11 18:29:08 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	sdl_key_down_2(t_sdl *sdl, t_farm data)
{
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
		close_window(sdl, data);
	if (sdl->event.key.keysym.sym == SDLK_UP)
	{
		if (sdl->ant_radius < 40)
			sdl->ant_radius += 1;
		SDL_Delay(4);
	}
	if (sdl->event.key.keysym.sym == SDLK_LEFT)
	{
		if (sdl->room_radius < 30)
			sdl->room_radius++;
		SDL_Delay(4);
	}
	if (sdl->event.key.keysym.sym == SDLK_RIGHT)
	{
		if (sdl->room_radius > 10)
			sdl->room_radius--;
		SDL_Delay(4);
	}
	if (sdl->event.key.keysym.sym == SDLK_1)
		sdl->delay = 1;
	if (sdl->event.key.keysym.sym == SDLK_2)
		sdl->delay = 5;
}

void	sdl_key_down(t_sdl *sdl, t_farm data)
{
	sdl_key_down_2(sdl, data);
	if (sdl->event.key.keysym.sym == SDLK_DOWN)
	{
		if (sdl->ant_radius > 3)
			sdl->ant_radius -= 1;
		SDL_Delay(4);
	}
	if (sdl->event.key.keysym.sym == SDLK_3)
		sdl->delay = 15;
	if (sdl->event.key.keysym.sym == SDLK_SPACE)
	{
		while (1)
		{
			SDL_PollEvent(&sdl->event);
			if (sdl->event.type == SDL_KEYDOWN)
			{
				if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
					sdl_key_down_2(sdl, data);
				if (sdl->event.key.keysym.sym == SDLK_SPACE)
					return ;
			}
		}
	}
}

void	sdl_events(t_sdl *sdl, t_farm data)
{
	SDL_PollEvent(&sdl->event);
	if (sdl->event.type == SDL_QUIT)
		close_window(sdl, data);
	if (sdl->event.type == SDL_KEYDOWN)
		sdl_key_down(sdl, data);
}