/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_farm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/11/10 13:04:09 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_FARM_H
# define ANT_FARM_H

# include "error_types.h"
# include "libft.h"
# include "ft_printf.h"
# include "hashmap.h"
# include "queue.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>

# define WIDTH 1200
# define HEIGHT 1000
# define STR_MSG 0
# define END_MSG 0
# define STDIN 0
# define MIN_STEPS (INT_MAX)
# define ANTS_REACHED_TO_END 0
# define MAX_SIZE 6000

typedef struct		s_fdf
{
	float			x1;
	float			y1;
	float			x;
	float			y;
	float			x_step;
	float			y_step;
	int				draw;
}					t_fdf;

typedef struct		s_ants
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				done;
}					t_ants;

typedef struct		s_route
{
	t_queue			*cur;
	t_queue			*new;
}					t_route;

typedef struct		s_room
{
	int				x;
	int				y;
	t_table			*in;
	bool			is_dup;
	t_table			*member;
	int				nbr_arcs;
	t_list			*neighbors;
	t_route			*route;
}					t_room;

typedef struct		s_link
{
	t_table			*linked;
	bool			is_lock;
}					t_link;

typedef struct		s_bfs
{
	t_queue			*q;
	t_hashmap		*visited;
}					t_bfs;

typedef struct		s_path
{
	int				found;
	int				*lengths;
	t_list			*all;
}					t_path;

typedef struct		s_farm
{
	char			*line;
	int				ants;
	short			err;
	int				nbr_edges;
	int				max_paths;
	t_path			*paths;
	t_hashmap		*rooms;
	t_table			*src;
	t_table			*sink;
	t_table			*vis[200];
	int				pos;
	int				visual;
}					t_farm;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Event		event;
	t_ants			*ant;
	t_farm			*farm;
	int				start;
	int				count;
	int				delay;
	Mix_Music		*music;
	int				ant_radius;
	int				room_radius;
	int				done;
	int				visual;
}					t_sdl;

short				parse_input(t_farm *data, short start_msg, short end_msg);
void				define_command(t_farm *data, short *start, short *end);
void				define_link(t_farm *data);

void				find_solution(t_farm *data, int min_steps);
t_path				*find_path(t_farm *data);
void				prepare_paths(t_path *paths, void *src, void *sink);
t_path				*restore_path(t_farm *data, t_table *sink);
void				optimization(t_route *route);
t_path				*sort_paths(t_queue *start_nodes);
t_queue				*copy_route(t_queue *cur);

void				print_solution(t_path *data, int ants, int reached,
									t_sdl *sdl);

void				throw_error(t_farm data);
void				clear_paths(t_path *paths);
void				del_value(void *val);

void				init_sdl(t_sdl *sdl);
void				close_window(t_sdl *sdl, t_farm *data, t_hashmap *output);
void				draw_background(t_sdl *sdl, t_farm *data,
									t_hashmap	*output);
void				draw_circle(int x, int y, int radius, t_sdl *sdl);
int					count_done(t_sdl *sdl, t_farm *data);
void				fill_ants(t_sdl *sdl, t_farm *data);
void				draw_movements(t_sdl *sdl, t_farm *data, t_hashmap *output);
void				note_movements(t_sdl *sdl, int index, const char *room);
void				sdl_events(t_sdl *sdl, t_farm *data, t_hashmap	*output);
void				draw_circles(t_sdl *sdl, t_farm *data, int radius);
void				draw_connections(t_sdl *sdl, t_farm *data);

#endif
