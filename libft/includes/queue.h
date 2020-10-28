/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:41:49 by dshala            #+#    #+#             */
/*   Updated: 2020/09/19 12:57:26 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "lists.h"
# include "stdlib.h"

typedef struct		s_queue
{
	t_list			*head;
	t_list			*tail;
	size_t			nbr_elem;
}					t_queue;

short				is_empty(t_queue *q);
void				*dequeue(t_queue *q);
void				remove_queue(t_queue *q);
t_queue				*init_queue(void);
t_list				*enqueue(t_queue *q, void *src);

#endif
