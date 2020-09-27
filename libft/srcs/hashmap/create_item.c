/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

t_item		*create_item(char const *key, t_value *value)
{
	t_item	*item;

	if (key == NULL || value == NULL)
		return (NULL);
	item = (t_item*)malloc(sizeof(t_item));
	ISNULL(item);
	item->hash_code = get_hashcode(key);
	item->key = ft_strdup(key);
	ISNULL(item->key);
	ft_memcpy(&item->value, (void*)value, sizeof(t_value));
	return (item);
}
