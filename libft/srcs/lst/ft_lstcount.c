/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:01:14 by dshala            #+#    #+#             */
/*   Updated: 2019/09/19 12:56:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lstcount(t_list *lst)
{
	int		counter;
	t_list	*cur;

	counter = 0;
	cur = lst;
	while (cur != NULL)
	{
		counter++;
		cur = cur->next;
	}
	return (counter);
}
