/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

static void	clear_lsts(t_list *head)
{
	t_list	*to_delete;

	while (head)
	{
		to_delete = head;
		head = head->next;
		ft_memdel((void**)&to_delete);
	}
}

void		remove_table(t_table *table)
{
	if (table != NULL)
	{
		ft_memdel((void**)&table->key);
		clear_lsts(table->value.links);
		ft_memdel((void**)&table);
	}
}
