/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2020/10/15 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant_farm.h"

static void 			add_inner_room(t_table *inner, t_table *from, t_bfs *bfs)
{
	if (!get_elem(bfs->visited, inner->key))
	{
		if (from)
			((t_room*)inner->value)->member = from;
		enqueue(bfs->q, inner);
		IF_FAIL(put_elem(&bfs->visited, inner->key, inner->value));
	}
}

static void 			add_plain_neighbors(t_table *node, t_bfs *bfs)
{
	t_list	*neig;
	t_table *cur_neig;

	neig = ((t_room*)node->value)->neighbors;
	while (neig)
	{
		cur_neig = ((t_link*)neig->content)->linked;
		if (!((t_link*)neig->content)->is_lock)
		{
			if (((t_room*)cur_neig->value)->in)
				add_inner_room(((t_room*)cur_neig->value)->in, node, bfs);
			else if (!get_elem(bfs->visited, cur_neig->key))
			{
				((t_room*)cur_neig->value)->member = node;
				enqueue(bfs->q, cur_neig);
				IF_FAIL(put_elem(&bfs->visited, cur_neig->key, cur_neig->value));
			}
		}
		neig = neig->next;
	}
}

static void				add_neighbor(t_hashmap *rooms, t_table *node, t_bfs *bfs)
{
	t_table	*member;
	t_table	*origin;

	if (((t_room*)node->value)->is_dup)
	{
		origin = get_table(rooms, node->key + 1);
		member = ((t_room*)origin->value)->member;
		if (!get_elem(bfs->visited, member->key))
		{
			((t_room*)member->value)->member = node;
			enqueue(bfs->q, member);
			IF_FAIL(put_elem(&bfs->visited, member->key, member->value));
		}
	}
	else
	{
		if (((t_room*)node->value)->in)
			add_inner_room(((t_room*)node->value)->in, NULL, bfs);
		add_plain_neighbors(node, bfs);
	}
}

static t_bfs			*init_bfs(t_table *src)
{
	t_bfs	*search;

	search = (t_bfs*)malloc(sizeof(t_bfs));
	IF_FAIL(search);
	search->q = init_queue();
	search->visited = init_hashmap(MAX_SIZE / 2, NULL);
	IF_FAIL(put_elem(&search->visited, src->key, src->value));
	enqueue(search->q, src);
	return (search);
}

t_path					*find_path(t_farm *data)
{
	t_bfs		*search;
	t_table		*cur;
	bool		is_exist;

	search = init_bfs(data->src);
	is_exist = false;
	prepare_paths(data->paths, data->src, data->sink);
	while (!is_empty(search->q))
	{
		cur = dequeue(search->q);
		if (cur == data->sink && (is_exist = true))
			break ;
		add_neighbor(data->rooms, cur, search);
	}
	remove_hashmap(search->visited);
	remove_queue(search->q);
	ft_memdel((void**)&search);
	return (is_exist ? restore_path(data, data->sink) : NULL);
}
