/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:49:41 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/13 12:32:11 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	fill_fdf(t_fdf *fdf, t_sdl *sdl, int i)
{
	if (((int)(fdf[i].x - fdf[i].x1)) || ((int)(fdf[i].y - fdf[i].y1)))
	{
		fdf[i].x += fdf[i].x_step;
		fdf[i].y += fdf[i].y_step;
		fdf[i].draw = 1;
	}
	else
	{
		sdl->ant[i].x = sdl->ant[i].x1;
		sdl->ant[i].y = sdl->ant[i].y1;
	}
}

void	draw_new_year(t_fdf *fdf, t_sdl *sdl, int i)
{
	int color;

	color = rand() % 9 + 1;
	if (!(color % 9))
		SDL_SetRenderDrawColor(sdl->render, 243, 243, 243, 255);
	else if (!(color % 8))
		SDL_SetRenderDrawColor(sdl->render, 225, 74, 154, 255);
	else if (!(color % 7))
		SDL_SetRenderDrawColor(sdl->render, 189, 213, 65, 255);
	else if (!(color % 6))
		SDL_SetRenderDrawColor(sdl->render, 68, 202, 117, 255);
	else if (!(color % 5))
		SDL_SetRenderDrawColor(sdl->render, 164, 225, 235, 255);
	else if (!(color % 4))
		SDL_SetRenderDrawColor(sdl->render, 0, 102, 102, 255);
	else if (!(color % 3))
		SDL_SetRenderDrawColor(sdl->render, 255, 0, 0, 255);
	else if (!(color % 2))
		SDL_SetRenderDrawColor(sdl->render, 0, 255, 0, 255);
	else
		SDL_SetRenderDrawColor(sdl->render, 0, 0, 255, 255);
	draw_circle(fdf[i].x, fdf[i].y, sdl->ant_radius, sdl);
}

void	draw_typical(t_fdf *fdf, t_sdl *sdl, int i)
{
	if (!(i % 4))
		SDL_SetRenderDrawColor(sdl->render, 0, 102, 102, 255);
	else if (!(i % 3))
		SDL_SetRenderDrawColor(sdl->render, 255, 0, 0, 255);
	else if (!(i % 2))
		SDL_SetRenderDrawColor(sdl->render, 0, 255, 0, 255);
	else
		SDL_SetRenderDrawColor(sdl->render, 0, 0, 255, 255);
	draw_circle(fdf[i].x, fdf[i].y, sdl->ant_radius, sdl);
}

void	fill_render(t_sdl *sdl, t_farm data, t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < data.ants)
	{
		if (fdf[i].draw == 1)
		{
			if (sdl->new_year)
				draw_new_year(fdf, sdl, i);
			else
				draw_typical(fdf, sdl, i);
		}
		i++;
	}
	draw_background(sdl, data);
	sdl_events(sdl);
	SDL_Delay(sdl->delay);
	SDL_RenderPresent(sdl->render);
	SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255);
	SDL_RenderClear(sdl->render);
}

void	draw_movements(t_sdl *sdl, t_farm data)
{
	t_fdf	fdf[data.ants];
	int		i;

	i = 0;
	init_fdf(fdf, sdl, data.ants);
	while (i < data.ants)
	{
		fill_fdf(fdf, sdl, i);
		if (i == data.ants - 1)
			fill_render(sdl, data, fdf);
		if (i == data.ants - 1 && !count_done(sdl, data.ants))
			i = -1;
		i++;
	}
}
