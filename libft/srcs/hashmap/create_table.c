/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "libft.h"

t_table		*create_table(char const *key, void *value, size_t value_size)
{
	t_table	*table;

	if (key == NULL || value == NULL)
		return (NULL);
	table = (t_table*)malloc(sizeof(t_table));
	ISNULL(table);
	table->hash_code = get_hashcode(key);
	table->key = ft_strdup(key);
	ISNULL(table->key);
	table->value = malloc(value_size);
	ISNULL(table->value);
	ft_memcpy(table->value, value, value_size);
	return (table);
}
