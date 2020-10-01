/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "libft.h"

t_list		*ft_lstcreate(void *src, size_t size)
{
	t_list	*new_lst;

	new_lst = (t_list*)ft_memalloc(sizeof(t_list));
	IF_FAIL(new_lst);
	new_lst->content_size = size;
	new_lst->content = src;
	new_lst->next = NULL;
	return (new_lst);
}
