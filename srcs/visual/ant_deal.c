/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:48:07 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/12 12:30:28 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	init_fdf(t_fdf *fdf, t_sdl *sdl, int ants)
{
	int	i;
	int max;

	i = 0;
	while (i < ants)
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

void	fill_ants(t_sdl *sdl, t_farm data)
{
	int		i;
	t_table	*src;
	t_room	*room;

	sdl->ant = (t_ants *)malloc(sizeof(t_ants) * data.ants);
	i = 0;
	src = data.src;
	room = (t_room *)src->value;
	while (i < data.ants)
	{
		sdl->ant[i].x = room->x;
		sdl->ant[i].y = room->y;
		sdl->ant[i].x1 = room->x;
		sdl->ant[i].y1 = room->y;
		i++;
	}
}

int		count_done(t_sdl *sdl, int ants)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < ants)
	{
		if (sdl->ant[i].x == sdl->ant[i].x1 && sdl->ant[i].y == sdl->ant[i].y1)
			res++;
		i++;
	}
	if (res != ants)
		return (0);
	return (1);
}
