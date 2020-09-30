//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

void 		__CHECK_VALIDATION__(void)
{
	t_farm data;

	data.is_err = -1;
	bzero((void*)g_path, SIZE);
	strncpy(g_path, ABS_PATH, BIAS);
	//__ANTS__(&data);
	//__COMMENTS__(&data);
	__ROOMS__(&data);
}