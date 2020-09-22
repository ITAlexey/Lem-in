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

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	while (alst && del && *alst != NULL)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
}
