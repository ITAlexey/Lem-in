//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

static void 	__test_ants__(t_farm *data, char *test_name, int err_code)
{
	printf("Test: %-35s", test_name);
	get_nbr_of_ants(data);
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
}

void 		__ANTS__(t_farm *data)
{
	printf("Passing txt:\n");
	data->fd = open(ft_strcat(g_path, "ant/ants"), O_RDONLY);
	__test_ants__(data, "Empty line", 0);
	__test_ants__(data, "Invalid format", 0);
	__test_ants__(data, "Negative number", 0);
	__test_ants__(data, "Too big number", 0);
	__test_ants__(data, "Valid format", -1);
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}