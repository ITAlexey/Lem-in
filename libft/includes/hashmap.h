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
	void			(*del)(void *);
}					t_hashmap;

typedef struct		s_table
{
	unsigned int	hash_code;
	char const		*key;
	void			*value;
}					t_table;

t_hashmap			*init_hashmap(int table_size, void (*f)(void *));
t_table				*create_table(char const *key, void *value);
void				remove_table(t_table *table, void (*f)(void *));
unsigned int		get_hashcode(const char *str);
void				*put_elem(t_hashmap **data, char const *key, void *value);
void				*get_elem(t_hashmap *data, char const *key);
short				is_elem_contained(t_hashmap *data, char const *key);
void				remove_elem(t_hashmap *data, char const *key);
void				remove_hashmap(t_hashmap *data);
void				*resize_hashmap(t_hashmap **data);
void				iterate_hashmap(t_hashmap *data, void (*fun)(t_list *));
t_table				*get_table(t_hashmap *data, char const *key);
t_table				**cast_to_array(t_hashmap *data);

#endif
