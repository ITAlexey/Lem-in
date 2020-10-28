//
// Created by alexey on 28.10.2020.
//

#include "ant_farm.h"


static void	lst_swap(t_list **head, t_list *cur,
				t_list *prev, t_list *elem)
{
	if (prev == NULL)
	{
		*head = elem;
		(*head)->next = cur;
	}
	else
	{
		prev->next = elem;
		elem->next = cur;
	}
}

static void collect_paths(t_list **head, t_list *path)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*elem;

	elem = ft_lstcreate(path, path->content_size);
	IF_FAIL(elem);
	prev = NULL;
	cur = *head;
	while (cur)
	{
		if (cur->content_size > elem->content_size)
			return (lst_swap(head, cur, prev, elem));
		prev = cur;
		cur = cur->next;
	}
	prev->next = elem;
}

static void connect_path(t_list *path, t_route *route)
{
	t_table *tmp;

	if (route)
	{
		tmp = dequeue(route->new);
		ft_lstpushback(path, ft_lstcreate(tmp, 0));
		path->content_size++;
		remove_queue(route->new);
		connect_path(path, ((t_room*)tmp->value)->route);
	}
}

t_path		*sort_paths(t_queue *start_nodes)
{
	t_path		*new;
	t_list		*path;
	t_table		*tmp;
	int 		idx;

	idx = 0;
	new = (t_path*)malloc(sizeof(t_path));
	IF_FAIL(new);
	new->found = start_nodes->nbr_elem;
	new->lengths = (int*)ft_memalloc(sizeof(int) * new->found);
	new->all = NULL;
	while ((tmp = dequeue(start_nodes)))
	{
		path = ft_lstcreate(tmp, 1);
		connect_path(path, ((t_room*)tmp->value)->route);
		new->lengths[idx++] = (int)path->content_size;
		if (!new->all)
		{
			new->all = ft_lstcreate(path, path->content_size);
			IF_FAIL(new->all);
		}
		else
			collect_paths(&new->all, path);
	}
	remove_queue(start_nodes);
	return (new);
}