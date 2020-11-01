//
// Created by alexey on 22.09.2020.
//

#ifndef ANT_FARM_H
#define ANT_FARM_H
# include "hashmap.h"
# include "error_types.h"
# include "libft.h"
# include "ft_printf.h"
# include "stdio.h"
# include "queue.h"
# include <stdbool.h>
# define INPUT "middle.txt"

typedef struct		s_route
{
	t_queue			*cur;
	t_queue			*new;
}					t_route;

typedef struct		s_room
{
	int 			x;
	int 			y;
	t_table			*in;
	bool 			is_dup;
	t_table 		*member;
	int 			nbr_arcs;
	t_list			*neighbors;
	t_route			*route;
}					t_room;

typedef struct		s_link
{
	t_table			*linked;
	bool 			is_lock;
}					t_link;

typedef struct		s_bfs
{
	t_queue			*q;
	t_hashmap		*visited;
}					t_bfs;

typedef struct 		s_path
{
	int 			found;
	int 			*lengths;
	t_list			*all;
}					t_path;

typedef struct 		s_farm
{
	int		 		fd;
	char 			*line;
	int 			ants;
	short 			err;
	int 			nbr_edges;
	int 			max_paths;
	t_path			*paths;
	t_hashmap		*rooms;
	t_table 		*src;
	t_table 		*sink;
}					t_farm;

short 			parse_input(t_farm *data, short start_msg, short end_msg);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);

void 			find_solution(t_farm *data, int min_steps);
t_path 			*find_path(t_farm *data, t_table *src, t_table *sink);
void 			prepare_paths(t_path *paths, void *src, void *sink);
t_path			*restore_path(t_farm *data, t_table *sink);
void 			optimization(t_route *route);
void			find_collisions(t_table *pattern, t_route *route);
t_path			*sort_paths(t_queue *start_nodes);
t_queue			*copy_route(t_queue *cur);

void 			print_queue(t_queue *q);
void 			print_path(t_path *paths);
void 			throw_error(t_farm data);
void 			clear_paths(t_path *paths);
short 			is_equal(void *a, void *b);
void 			del_value(void *val);
#endif
