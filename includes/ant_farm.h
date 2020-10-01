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

typedef struct	s_typeroom
{
	t_hashmap	*start;
	t_hashmap	*end;
	t_hashmap	*plain;
	int 		start_size;
	int 		end_size;
	int 		plain_size;
}				t_typeroom;

typedef struct 	s_farm
{
	int		 	fd;
	char 		*line;
	int 		ants;
	short 		is_err;
	int 		links_nbr;
	char 		*err_lst[ERRORS];
	t_typeroom	room_type;
}				t_farm;

void 			parse_input(t_farm *data);
void 			define_command(t_farm *data, short *start, short *end);
void 			define_link(t_farm *data);

#endif
