/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/10/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static t_link		*init_link(t_table *dest)
{
	t_link	*link;

	link = (t_link*)malloc(sizeof(t_link));
	ISNULL(link);
	link->linked = dest;
	link->is_lock = false;
	return (link);
}

static void			link_rooms(t_table *src, t_table *dest)
{
	t_link	*link;

	link = init_link(dest);
	IF_FAIL(link);
	if (((t_room*)src->value)->nbr_arcs == 0)
		((t_room*)src->value)->neighbors = ft_lstcreate(link, 0);
	else
		ft_lstadd(&((t_room*)src->value)->neighbors, ft_lstcreate(link, 0));
	((t_room*)src->value)->nbr_arcs++;
}

void				define_link(t_farm *data)
{
	char		**data_link;
	t_table		*right;
	t_table		*left;

	if (!data->src || !data->sink)
		data->err = !data->sink ? ERR_END : ERR_START;
	else
	{
		data_link = ft_strsplit(data->line, '-');
		IF_FAIL(data_link);
		if ((left = get_table(data->rooms, data_link[0])) != NULL
			&& (right = get_table(data->rooms, data_link[1])) != NULL
			&& ft_strcmp(left->key, right->key))
		{
			data->nbr_edges++;
			link_rooms(left, right);
			link_rooms(right, left);
		}
		else
			data->err = ERR_LINK;
		ft_free2darray((void**)data_link);
	}
}
