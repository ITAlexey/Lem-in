//
// Created by alexey on 01.10.2020.
//

#include "ant_farm.h"

static void 		record_link(t_table *main_table, t_table *bounded_table)
{
	if (main_table->value.connections == 0)
		main_table->value.links = ft_lstcreate(bounded_table, sizeof(t_list));
	else
		ft_lstpushback(main_table->value.links, ft_lstcreate(bounded_table, sizeof(t_list)));
	main_table->value.connections++;
}

static t_table		*is_room_exist(t_typeroom types, char *key)
{
	t_table *table;

	if ((table = get_table(types.start, key)) != NULL)
		return (table);
	else if ((table = get_table(types.end, key)) != NULL)
		return (table);
	else if (types.plain_size && (table = get_table(types.plain, key)) != NULL)
		return (table);
	return (NULL);
}

void 		define_link(t_farm *data)
{
	char 		**data_link;
	t_table		*basic;
	t_table		*bounded;

	if (!data->room_type.start_size || !data->room_type.end_size)
		data->is_err = !data->room_type.end_size ? ERR_END : ERR_START;
	else
	{
		data_link = ft_strsplit(data->line, '-');
		IF_FAIL(data_link);
		if ((basic = is_room_exist(data->room_type, data_link[0])) != NULL
			&& (bounded = is_room_exist(data->room_type, data_link[1])) != NULL)
		{
			data->links_nbr++;
			record_link(basic, bounded);
		}
		else
			data->is_err = ERR_LINK;
		ft_free2darray((void**)data_link);
	}
}