/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

t_hashmap		*init_hashmap(int table_size, void (*f)(void *))
{
	int			idx;
	t_hashmap	*hashmap;

	idx = 0;
	hashmap = (t_hashmap*)ft_memalloc(sizeof(t_hashmap));
	ISNULL(hashmap);
	hashmap->occupied_cells = 0;
	hashmap->load_factor = 0;
	hashmap->del = f;
	hashmap->size = table_size;
	hashmap->arr = (t_list*)ft_memalloc(sizeof(t_list) * table_size);
	ISNULL(hashmap->arr);
	while (idx < table_size)
	{
		hashmap->arr[idx].content_size = 0;
		hashmap->arr[idx].next = NULL;
		idx++;
	}
	return (hashmap);
}
