/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:45:10 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/13 12:07:26 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	draw_connections(t_sdl *sdl, t_farm data)
{
	int		i;
	t_room	*room;
	t_list	*neighbors;
	t_link	*link;
	t_room	*room2;

	i = 0;
	SDL_SetRenderDrawColor(sdl->render, 255, 255, 255, 255);
	while (data.arr[i] != NULL)
	{
		room = data.arr[i]->value;
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
			if ((dx * dx + dy * dy) <= (radius * radius))
				SDL_RenderDrawPoint(sdl->render, x + dx, y + dy);
			h++;
		}
		w++;
	}
}

void	draw_circles(t_sdl *sdl, t_farm data, int radius)
{
	t_room	*room;
	t_room	*sink;
	t_room	*src;
	int		i;

	i = 0;
	src = data.src->value;
	sink = data.sink->value;
	while (data.arr[i] != NULL)
	{
		SDL_SetRenderDrawColor(sdl->render, 64, 64, 64, 200);
		room = data.arr[i]->value;
		if (room->x == sink->x && room->y == sink->y)
			SDL_SetRenderDrawColor(sdl->render, 255, 255, 0, 255);
		if (room->x == src->x && room->y == src->y)
			SDL_SetRenderDrawColor(sdl->render, 255, 255, 0, 255);
		draw_circle(room->x, room->y, radius, sdl);
		i++;
	}
}

void	draw_background(t_sdl *sdl, t_farm data)
{
	sdl_events(sdl);
	SDL_SetRenderDrawColor(sdl->render, 0, 0, 0, 0);
	draw_connections(sdl, data);
	draw_circles(sdl, data, sdl->room_radius);
	SDL_RenderPresent(sdl->render);
}
