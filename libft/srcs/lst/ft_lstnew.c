/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:18:48 by dshala            #+#    #+#             */
/*   Updated: 2019/09/27 14:09:48 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *src, size_t size)
{
	t_list		*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!src)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = malloc(size)))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, src, size);
		tmp->content_size = size;
	}
	tmp->next = NULL;
	return (tmp);
}
