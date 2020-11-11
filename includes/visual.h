//
// Created by alexey on 11.11.2020.
//

#ifndef VISUAL_H
# define VISUAL_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
# include "ant_farm.h"

# define WIDTH 1200
# define HEIGHT 1000

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

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Event		event;
	t_ants			*ant;
	int				start;
	int				count;
	int				delay;
	Mix_Music		*music;
	int				ant_radius;
	int				room_radius;
	int				done;
	int				visual;
}					t_sdl;

void				init_sdl(t_sdl *sdl);
void				close_window(t_sdl *sdl, t_farm data);
void				draw_background(t_sdl *sdl, t_farm data);
void				draw_circle(int x, int y, int radius, t_sdl *sdl);
int					count_done(t_sdl *sdl, t_farm data);
void				fill_ants(t_sdl *sdl, t_farm data);
void				draw_movements(t_sdl *sdl, t_farm data);
void				note_movements(t_sdl *sdl, int index, const char *room, t_farm data);
void				sdl_events(t_sdl *sdl, t_farm data);
void				draw_circles(t_sdl *sdl, t_farm data, int radius);
void				draw_connections(t_sdl *sdl, t_farm data);

#endif
