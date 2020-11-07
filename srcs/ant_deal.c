/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:48:07 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/07 16:14:17 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

void	fill_ants(t_sdl *sdl, t_farm *data)
{
	int     i;
    t_table *src;
    t_room  *room;

	sdl->ant = (t_ants *)malloc(sizeof(t_ants) * data->ants);
	i = 0;
	src = data->src;
	room = (t_room *)src->value;
	while (i < data->ants)
	{
		sdl->ant[i].x = room->x;
		sdl->ant[i].y = room->y;
		sdl->ant[i].x1 = room->x;
		sdl->ant[i].y1 = room->y;
		i++;
	}
}

int		count_done(t_sdl *sdl, t_farm *data)
{
	int i = 0;
	int res = 0;
	while (i < data->ants)
	{
		if (sdl->ant[i].x == sdl->ant[i].x1 && sdl->ant[i].y == sdl->ant[i].y1)
			res++;
		i++;
	}
	return (res);
}
