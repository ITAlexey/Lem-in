//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

static void 		__test_comment__(t_farm *data, char *test_name, int err_code, char *path)
{
	short start;
	short end;

	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(path, O_RDONLY);
	while (get_next_line(data->fd, &data->line))
	{
		define_comment(data, &start, &end);
		ft_strdel(&data->line);
	}
	data->is_err == err_code ? success() : fail();
	data->is_err = -1;
	close(data->fd);
	bzero((void*)(g_path + BIAS), SIZE - BIAS);
}

void 		__COMMENTS__(t_farm *data)
{
	printf("\nCheck comments:\n");
	__test_comment__(data, "Valid start command", -1, ft_strcat(g_path, "comments/comment_start"));
	__test_comment__(data, "Valid end command", -1, ft_strcat(g_path, "comments/comment_end"));
	__test_comment__(data, "Simple comment", -1, ft_strcat(g_path, "comments/comment"));
	__test_comment__(data, "Multiple start commands", 1, ft_strcat(g_path, "comments/multiple_start"));
	__test_comment__(data, "Multiple end commands", 1, ft_strcat(g_path, "comments/multiple_end"));
}