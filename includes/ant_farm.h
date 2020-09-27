//
// Created by alexey on 22.09.2020.
//

#ifndef ANT_FARM_H
#define ANT_FARM_H
# include "libft.h"

typedef struct	s_room
{
	int 		x;
	int 		y;
	char		*name;
}				t_room;

typedef struct	s_typeroom
{
	int 		plain;
	int 		start;
	int 		end;
}				t_typeroom;

typedef struct 	s_farm
{
	int 		ants;
	s_typeroom	type;
	t_room 		*rooms;
}				t_farm;

#endif
