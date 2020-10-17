/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:41:49 by dshala            #+#    #+#             */
/*   Updated: 2020/09/19 12:57:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void			remove_queue(t_queue *q)
{
	t_list	*to_delete;

	if (q != NULL)
	{
		while (q->head)
		{
			to_delete = q->head;
			q->head = q->head->next;
			free(to_delete);
		}
		free(q);
		q = NULL;
	}
}
