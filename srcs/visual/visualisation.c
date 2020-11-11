/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:13:40 by tclarita          #+#    #+#             */
/*   Updated: 2020/11/11 18:33:46 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"
#include "visual.h"

void	note_movements(t_sdl *sdl, int index, const char *room, t_farm data)
{
	int		i;
	t_room	*res;

	i = 0;
	sdl->start = 1;
	while (ft_strcmp(room, data.arr[i]->key))
		i++;
	if (data.arr[i]->key == NULL)
		return ;
	res = data.arr[i]->value;
	sdl->ant[index - 1].x1 = res->x;
	sdl->ant[index - 1].y1 = res->y;
}

void	get_steps(char *line, t_sdl *sdl, t_farm farm)
{
	char	**tmp;
	char	**res;
	int		i;

	tmp = ft_strsplit(line, ' ');
	i = 0;
	while (tmp[i])
	{
		res = ft_strsplit(tmp[i], '-');
		note_movements(sdl, ft_atoi(res[0] + 1), res[1], farm);
		i++;
		ft_free2darray((void**)res);
	}
	ft_free2darray((void**)tmp);
	draw_movements(sdl, farm);
	ft_strdel(&line);
}

void	visualisation(t_farm farm, char *path)
{
	t_sdl	sdl[1];
	char	*line;
	int		fd;

	init_sdl(sdl);
	fill_ants(sdl, farm);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
		get_steps(line, sdl, farm);
	close(fd);
}
