/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_hashmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void		iterate_hashmap(t_hashmap *data, void (*fun)(t_list *))
{
	int	idx;

	idx = 0;
	while (idx < data->size)
	{
		if (data->arr[idx].content_size != 0)
			ft_lstiter(&data->arr[idx], fun);
		idx++;
	}
}
