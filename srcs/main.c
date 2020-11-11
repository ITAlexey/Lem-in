/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/10 12:50:02 by tclarita         ###   ########.fr       */
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

void 	visualisation(t_farm farm, char *path)
{
	t_sdl sdl[1];
	char **tmp;
	char *line;
	char **res;
	int fd;
	init_sdl(sdl);
	fill_ants(sdl, farm);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		int i = 0;
		while(tmp[i]) {
			res = ft_strsplit(tmp[i], '-');
			note_movements(sdl, ft_atoi(res[0] + 1), res[1], farm);
			i++;
			ft_free2darray((void**)res);
		}
		ft_free2darray((void**)tmp);
		draw_movements(sdl, farm);
		ft_strdel(&line);
	}
	close(fd);
}

int	main(int ac, char *av[])
{
	t_farm		data;

	if (!parse_input(&data, STR_MSG, END_MSG))
		throw_error(data);
	find_solution(&data, MIN_STEPS);
	print_solution(data.paths, data.ants, ANTS_REACHED_TO_END);
	if (ac == 3 && ft_strequ("-v", av[1]))
	{
		data.arr = cast_to_array(data.rooms);
		IF_FAIL(data.arr);
		visualisation(data, av[2]);
	}
	ft_memdel((void**)&data.arr);
	clear_paths(data.paths);
	remove_hashmap(data.rooms);
	return (0);
}
