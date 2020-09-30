//
// Created by alexey on 30.09.2020.
//

#ifndef TESTS_H
#define TESTS_H

# include "ant_farm.h"
# include <stdio.h>
# include <string.h>
# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define ABS_PATH "tests/validation/txt/"
# define SIZE 100
# define BIAS 21

char 	g_path[SIZE];

typedef struct	s_testroom
{
	char 		*path;
	char 		*test_name;
	short 		err_code;
	short 		finded_rooms;
	// plain start end
	char 		*room_names[6];


}				t_testroom;

void 	success(void);
void 	fail(void);
void 	__CHECK_VALIDATION__(void);
void 	__COMMENTS__(t_farm *data);
void 	__ANTS__(t_farm *data);
void 	__ROOMS__(t_farm *data);

#endif
