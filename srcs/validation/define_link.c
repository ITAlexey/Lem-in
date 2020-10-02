//
// Created by alexey on 01.10.2020.
//

#include "ant_farm.h"

static void 		record_link(t_table *origin_table, t_table *bounded_table)
{
	if (origin_table->value.connections == 0)
		origin_table->value.links = ft_lstcreate(bounded_table, sizeof(t_list));
	else
		ft_lstpushback(origin_table->value.links, ft_lstcreate(bounded_table, sizeof(t_list)));
	origin_table->value.connections++;
}

void 		define_link(t_farm *data)
{
	char 		**data_link;
	t_table		*origin_table;
	t_table		*bounded_table;

	if (!data->start_room || !data->end_room)
		data->is_err = !data->end_room ? ERR_END : ERR_START;
	else
	{
		data_link = ft_strsplit(data->line, '-');
		IF_FAIL(data_link);
		if ((origin_table = get_table(data->rooms, data_link[0])) != NULL
			&& (bounded_table = get_table(data->rooms, data_link[1])) != NULL)
		{
			data->links_nbr++;
			record_link(origin_table, bounded_table);
		}
		else
			data->is_err = ERR_LINK;
		ft_free2darray((void**)data_link);
	}
}