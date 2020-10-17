/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:41:49 by dshala            #+#    #+#             */
/*   Updated: 2020/09/19 12:57:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void			*dequeue(t_queue *q)
{
	t_list		*tmp;
	void		*result;

	if (is_empty(q))
		return (NULL);
	tmp = q->head;
	result = tmp->content;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	tmp = NULL;
	return (result);
}
