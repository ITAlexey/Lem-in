//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

static void 		__test_ants__(t_farm *data, char *test_name, int err_code)
{
	printf("Test: %-25s", test_name);
	get_nbr_of_ants(data);
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
}

static void 		__test_comment__(t_farm *data, char *test_name, int err_code, char *path)
{
	short start;
	short end;

	start = 0;
	end = 0;
	printf("Test: %-25s", test_name);
	data->fd = open(path, O_RDONLY);
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		define_comment(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
	close(data->fd);
}

void 		__CHECK_VALIDATION__(void)
{
	t_farm data;

	data.is_err = -1;
	//init_error_lists(data.err_lst);

	// test get_nbr_of_ants
	printf("Passing txt:\n");
	data.fd = open("tests/txt/ants", O_RDONLY);
	__test_ants__(&data, "Empty line", 0);
	__test_ants__(&data, "Invalid format", 0);
	__test_ants__(&data, "Negative number", 0);
	__test_ants__(&data, "Too big number", 0);
	__test_ants__(&data, "Valid format", -1);
	close(data.fd);

	// test define_comment
	printf("\nCheck comments:\n");
	__test_comment__(&data, "Valid start command", -1, "tests/txt/comment_start");
	__test_comment__(&data, "Valid end command", -1, "tests/txt/comment_end");
	__test_comment__(&data, "Simple comment", -1, "tests/txt/comment");
	__test_comment__(&data, "Multiple start commands", 1, "tests/txt/multiple_start");
	__test_comment__(&data, "Multiple end commands", 1, "tests/txt/multiple_end");

}