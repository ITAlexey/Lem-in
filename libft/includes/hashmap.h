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

typedef struct		s_value
{
	ssize_t			nbr;
	char			*str;
	double			db;
	char			sign;
}					t_value;

typedef struct		s_item
{
	unsigned int	hash_code;
	char const		*key;
	t_value			value;
}					t_item;

t_hashmap			*init_hashmap(int table_size);
t_item				*create_item(char const *key, t_value *value);
void				remove_item(t_item *item);
unsigned int		get_hashcode(const char *str);
void				*put_elem(t_hashmap **data, t_item *item);
t_value				*get_elem(t_hashmap *data, char const *key);
short				is_elem_contained(t_hashmap *data, char const *key);
void				remove_elem(t_hashmap *data, char const *key);
void				remove_hashmap(t_hashmap *data);
void				*resize_hashmap(t_hashmap **data);

#endif
