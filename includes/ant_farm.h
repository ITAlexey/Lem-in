//
// Created by alexey on 22.09.2020.
//

#ifndef ANT_FARM_H
#define ANT_FARM_H
# include "hashmap.h"
# include "error_types.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdbool.h>
# define INPUT "input.txt"

typedef struct		s_queue
{
	void 			*content;
	struct s_queue	*next;
	struct s_queue	*prev;
}					t_queue;

typedef struct	s_room
{
	int 		x;
	int 		y;
	short 		id;
	bool		is_visited;
	t_list		*neighbors;
	short 		nbr_arcs;
	short 		capacity;
	short 		flow;

}				t_room;

typedef struct 	s_farm
{
	int		 	fd;
	char 		*line;
	int 		ants;
	short 		is_err;
	int 		nbr_edges;
	int 		nbr_rooms;
	char 		*err_lst[ERRORS];
	t_hashmap	*rooms;
	char 		*start_room;
	char 		*end_room;
}				t_farm;

int 			parse_input(t_farm *data);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);

#endif
