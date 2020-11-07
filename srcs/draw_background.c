/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:45:10 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/07 16:13:18 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

void	draw_connections(t_sdl *sdl, t_farm *data)
{
	int		i;
	t_room	*room;
	t_list	*neighbors;
	t_link	*link;
	t_room	*room2;

	i = 0;
	SDL_SetRenderDrawColor(sdl->render, 255, 255, 255, 255);
	while (data->vis[i] != NULL)
	{
		room = data->vis[i]->value;
		neighbors = room->neighbors;
		while (neighbors != NULL)
		{
			link = neighbors->content;
			room2 = link->linked->value;
			SDL_RenderDrawLine(sdl->render, room->x, room->y,
											room2->x, room2->y);
			neighbors = neighbors->next;
		}
		i++;
	}
}

void	draw_circle(int x, int y, int radius, t_sdl *sdl)
{
	int w;
	int h;
	int dx;
	int dy;

	w = 0;
	while (w < radius * 2)
	{
		h = 0;
		while (h < radius * 2)
		{
			dx = radius - w;
			dy = radius - h;
			if ((dx*dx + dy*dy) <= (radius * radius))
				SDL_RenderDrawPoint(sdl->render, x + dx, y + dy);
			h++;
		}
		w++;
	}
}

void	draw_circles(t_sdl *sdl, t_farm *data, int radius)
{
	int		x;
	int		y;
	t_room	*room;
	t_room	*sink;
	t_room	*src;

	src = data->src->value;
	sink = data->sink->value;
	SDL_SetRenderDrawColor(sdl->render, 255, 255, 255, 255);
	int i = 0;
	while (data->vis[i] != NULL)
	{
		room =  data->vis[i]->value;
		SDL_SetRenderDrawColor(sdl->render, 140, 140, 140, 255);
		if (room->x == sink->x && room->y == sink->y)
			SDL_SetRenderDrawColor(sdl->render, 255, 0, 0, 255);
		if (room->x == src->x && room->y == src->y)
			SDL_SetRenderDrawColor(sdl->render, 255, 255, 0, 255);
		x = room->x;
		y = room->y;
		draw_circle(x, y, radius, sdl);
		i++;
	}
}

void	draw_background(t_sdl *sdl, t_farm *data)
{
	SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 0);
	draw_circles(sdl, data, 10);
	draw_connections(sdl, data);
	SDL_RenderPresent(sdl->render);
}
