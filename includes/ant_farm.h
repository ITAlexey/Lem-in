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
	bool			is_visited;
	t_list			*neighbors;
	short 			nbr_arcs;
	char 			*member;
}					t_room;

typedef struct		s_connection
{
	const char 		*room_name;
	short 			capacity;
	short 			flow;
}					t_connection;

typedef struct 	s_farm
{
	int		 	fd;
	char 		*line;
	int 		ants;
	short 		err;
	int 		nbr_edges;
	int 		nbr_rooms;
	char 		*err_lst[ERRORS];
	t_hashmap	*rooms;
	char 		*start_room;
	char 		*end_room;
	int 		max_nbr_paths;
}				t_farm;

int 			parse_input(t_farm *data);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);
char 			*bfs(t_farm *data);

#endif
