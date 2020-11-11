/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:49:41 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/10 11:19:29 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	init_fdf(t_fdf *fdf, t_sdl *sdl, t_farm data)
{
	int	i;
	int max;

	i = 0;
	while (i < data.ants)
	{
		fdf[i].x = sdl->ant[i].x;
		fdf[i].x1 = sdl->ant[i].x1;
		fdf[i].y = sdl->ant[i].y;
		fdf[i].y1 = sdl->ant[i].y1;
		fdf[i].x_step = fdf[i].x1 - fdf[i].x;
		fdf[i].y_step = fdf[i].y1 - fdf[i].y;
		max = MAX(ABC(fdf[i].x_step), ABC(fdf[i].y_step));
		fdf[i].x_step /= max;
		fdf[i].y_step /= max;
		fdf[i].draw = 0;
		i++;
	}
}

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

void	fill_render(t_sdl *sdl, t_farm data, t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < data.ants)
	{
		if (fdf[i].draw == 1)
		{
			if (!(i % 3))
				SDL_SetRenderDrawColor(sdl->render, 255, 0, 0, 255);
			else if (!(i % 2))
				SDL_SetRenderDrawColor(sdl->render, 0, 255, 0, 255);
			else
				SDL_SetRenderDrawColor(sdl->render, 0, 0, 255, 255);
			draw_circle(fdf[i].x, fdf[i].y, sdl->ant_radius, sdl);
		}
		i++;
	}
	draw_background(sdl, data);
	sdl_events(sdl, data);
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
	init_fdf(fdf, sdl, data);
	while (i < data.ants)
	{
		fill_fdf(fdf, sdl, i);
		if (i == data.ants - 1)
			fill_render(sdl, data, fdf);
		if (i == data.ants - 1 && !count_done(sdl, data))
			i = -1;
		i++;
	}
}
