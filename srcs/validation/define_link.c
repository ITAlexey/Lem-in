//
// Created by alexey on 01.10.2020.
//

#include "ant_farm.h"

static void 		link_rooms(t_table *src, t_table *dest)
{
	if (((t_room*)src->value)->nbr_arcs == 0)
		((t_room*)src->value)->neighbors = ft_lstcreate(dest, sizeof(t_list));
	else
		ft_lstpushback(((t_room*)src->value)->neighbors, ft_lstcreate(dest, sizeof(t_list)));
	((t_room*)src->value)->nbr_arcs++;
}

void 		define_link(t_farm *data)
{
	char 		**data_link;
	t_table		*right;
	t_table		*left;

	if (!data->start_room || !data->end_room)
		data->is_err = !data->end_room ? ERR_END : ERR_START;
	else
	{
		data_link = ft_strsplit(data->line, '-');
		IF_FAIL(data_link);
		if ((left = get_table(data->rooms, data_link[0])) != NULL
			&& (right = get_table(data->rooms, data_link[1])) != NULL)
		{
			data->nbr_edges++;
			link_rooms(left, right);
			link_rooms(right, left);
		}
		else
			data->is_err = ERR_LINK;
		ft_free2darray((void**)data_link);
	}
}