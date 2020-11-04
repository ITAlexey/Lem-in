/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:01:14 by dshala            #+#    #+#             */
/*   Updated: 2019/09/19 12:56:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list		*tmp;

	while (alst && *alst != NULL)
	{
		tmp = *alst;
		if (del)
			del((*alst)->content);
		*alst = (*alst)->next;
		free(tmp);
	}
	tmp = NULL;
	*alst = NULL;
}
