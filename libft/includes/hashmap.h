/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/08/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H
# define TABLE_SIZE 16
# define MAX_LOADING 0.75
# include "lists.h"
# include <stdlib.h>

typedef struct		s_hashmap
{
	float			load_factor;
	int				occupied_cells;
	int				size;
	t_list			*arr;
}					t_hashmap;

typedef struct		s_table
{
	unsigned int	hash_code;
	char const		*key;
	void 			*value;
}					t_table;

t_hashmap			*init_hashmap(int table_size);
t_table				*create_table(char const *key, void *value, size_t value_size);
void				remove_table(t_table *table);
unsigned int		get_hashcode(const char *str);
void				*put_elem(t_hashmap **data, t_table *table);
void				*get_elem(t_hashmap *data, char const *key);
short				is_elem_contained(t_hashmap *data, char const *key);
void				remove_elem(t_hashmap *data, char const *key);
void				remove_hashmap(t_hashmap *data);
void				*resize_hashmap(t_hashmap **data);
t_table				*get_table(t_hashmap *data, char const *key);

#endif
