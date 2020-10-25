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
	t_list			*neighbors;
	short 			nbr_arcs;
	char 			*member;
	bool 			is_dup;
	t_table			*in;
}					t_room;

typedef struct		s_link
{
	const char 		*room_name;
	bool 			is_lock;
}					t_link;

typedef struct		s_path
{
	int 			max;
	int 			found;
	t_list			*routes;
}					t_path;

typedef struct 		s_farm
{
	int		 		fd;
	char 			*line;
	int 			ants;
	short 			err;
	int 			nbr_edges;
	t_hashmap		*rooms;
	t_table 		*src;
	t_table 		*sink;
	t_path			paths;
}					t_farm;

int 			parse_input(t_farm *data);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);
t_list 			*bfs(t_farm *data, t_table *src, t_table *sink);
void 			throw_error(t_farm data);

#endif
