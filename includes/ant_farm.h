//
// Created by alexey on 22.09.2020.
//

#ifndef ANT_FARM_H
#define ANT_FARM_H
# include "hashmap.h"
# include "error_types.h"
# include "libft.h"
# include "ft_printf.h"
# include "queue.h"
# include <stdbool.h>
# define INPUT "input.txt"

typedef struct		s_room
{
	int 			x;
	int 			y;
	t_table			*in;
	bool 			is_dup;
	t_table 		*member;
	int 			nbr_arcs;
	t_list			*neighbors;
}					t_room;

typedef struct		s_link
{
	t_table			*linked;
	bool 			is_lock;
}					t_link;

typedef struct		s_path
{
	int 			found;
	t_list			*routes;
}					t_path;

typedef struct		s_bfs
{
	t_queue			q;
	t_hashmap		*visited;
	bool 			is_exist;
}					t_bfs;

typedef struct 		s_farm
{
	int		 		fd;
	char 			*line;
	int 			ants;
	short 			err;
	int 			nbr_edges;
	int 			max_paths;
	t_hashmap		*rooms;
	t_table 		*src;
	t_table 		*sink;
	t_path			*paths;
}					t_farm;

short 			parse_input(t_farm *data, short start_msg, short end_msg);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);
t_path 			*find_path(t_farm *data, t_table *src, t_table *sink);
void 			throw_error(t_farm data);
void 			find_solution(t_farm *data, int min_steps, int max);

#endif
