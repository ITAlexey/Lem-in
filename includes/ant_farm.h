//
// Created by alexey on 22.09.2020.
//

#ifndef ANT_FARM_H
#define ANT_FARM_H
# include "hashmap.h"
# include "error_types.h"
# include "libft.h"
# include "ft_printf.h"
# define INPUT "input.txt"

typedef struct 	s_farm
{
	int		 	fd;
	char 		*line;
	int 		ants;
	short 		is_err;
	int 		links_nbr;
	char 		*err_lst[ERRORS];
	t_hashmap	*rooms;
	char 		*start_room;
	char 		*end_room;
}				t_farm;

int 			parse_input(t_farm *data);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);

#endif
