/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:41:49 by dshala            #+#    #+#             */
/*   Updated: 2020/09/19 12:57:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list			*enqueue(t_queue *q, void *src)
{
	t_list		*new_node;

	if (q == NULL || src == NULL)
		return (NULL);
	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content_size = 0;
	new_node->content = src;
	new_node->next = NULL;
	if (q->head == NULL)
		q->head = new_node;
	if (q->tail != NULL)
		q->tail->next = new_node;
	q->tail = new_node;
	q->nbr_elem++;
	return (new_node);
}
