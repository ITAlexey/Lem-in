/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:49:41 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/07 16:13:27 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

typedef struct s_fdf
{
	float		x1;
	float		y1;
	float		x;
	float		y;
	float		x_step;
	float		y_step;
}				t_fdf;

void	note_movements(t_sdl *sdl, int index, const char *room)
{
	int i = 0;

	sdl->start = 1;
	while (ft_strcmp(room, sdl->farm->vis[i]->key))
	{
		i++;
	}
	if (sdl->farm->vis[i]->key == NULL)
		return ;
	t_room *res = sdl->farm->vis[i]->value;
	sdl->ant[index - 1].x1 = res->x;
	sdl->ant[index - 1].y1 = res->y;
}

void	draw_movements(t_sdl *sdl, t_farm *data)
{
	int radius = 7;
	t_fdf	fdf[data->ants];
	int i = 0;
	while (i < data->ants)
	{
		if (sdl->ant[i].x != sdl->ant[i].x1 || sdl->ant[i].y != sdl->ant[i].y1)
		{
			fdf[i].x_step = sdl->ant[i].x1 - sdl->ant[i].x;
			fdf[i].y_step = sdl->ant[i].y1 - sdl->ant[i].y;
			int max = MAX1(MOD(fdf[i].x_step), MOD(fdf[i].y_step));
			fdf[i].x_step /= max;
			fdf[i].y_step /= max;

			SDL_SetRenderDrawColor(sdl->render, 255, 0, 130, 255);
			draw_circle(sdl->ant[i].x, sdl->ant[i].y, radius, sdl);
			sdl->ant[i].x += fdf[i].x_step;
			sdl->ant[i].y += fdf[i].y_step;
		}
		if (i == data->ants - 1)
		{
			draw_background(sdl, data);
			SDL_Delay(3);
			SDL_RenderPresent(sdl->render);
			SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 255);
			SDL_RenderClear(sdl->render);
		}
		if (i == data->ants - 1 && count_done(sdl, data) != data->ants)
			i = -1;
		i++;
	}
}
