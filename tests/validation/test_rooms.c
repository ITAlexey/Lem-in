//
// Created by alexey on 30.09.2020.
//

#include "tests.h"

static void 		__test_room__(t_farm *data, t_testroom *room)
{
	short start;
	short end;
	int count_rooms;

	count_rooms = 0;
	start = 0;
	end = 0;
	printf("Test: %-35s", test_name);
	data->fd = open(path, O_RDONLY);
	data->links_nbr = 0;
	while (data->is_err < 0 && get_next_line(data->fd, &data->line))
	{
		if (*(data->line) == '#')
			define_comment(data, &start, &end);
		else
			define_command(data, &start, &end);
		ft_strdel(&data->line);
	}
	if (data->is_err == err_code)
		;
	else
		fail();
	data->is_err = -1;
	close(data->fd);
}

void 		__ROOMS__(t_farm *data)
{
	printf("\nCheck rooms:\n")
	__test_room__(data, "Record one plain room", -1, "tests/txt/room/", 1)
	__test_room__(data, "Record one start room", -1, "tests/txt/room/", 1);
	__test_room__(data, "Record one end room", -1, "tests/txt/room/", 1);
	__test_room__(data, "Record several plain room", -1, "tests/txt/room/", 3)
	__test_room__(data, "Record several start rooms", -1, "tests/txt/room/", 3);
	__test_room__(data, "Record several end rooms", -1, "tests/txt/room/", 3);
	__test_room__(data, "Record several plain, start and end rooms", -1, "tests/txt/room/", 6);
	__test_room__(data, "Invalid coordinates", 3, "tests/txt/room/", 0);
	__test_room__(data, "Name starts with L", 3, "tests/txt/room/", 0);
}