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
	t_list	*elem;

	if (route)
	{
		tmp = route->new->head->content;
		elem = ft_lstcreate(tmp, 0);
		IF_FAIL(elem);
		ft_lstpushback(path, elem);
		path->content_size++;
		connect_path(path, ((t_room*)tmp->value)->route);
	}
}

static void		f(t_table *node, t_path *path, int idx)
{
	t_list	*elem;

	elem = ft_lstcreate(node, 1);
	IF_FAIL(elem);
	connect_path(elem, ((t_room*)node->value)->route);
	path->lengths[idx] = (int)elem->content_size;
	if (!path->all)
	{
		path->all = ft_lstcreate(elem, elem->content_size);
		IF_FAIL(path->all);
	}
	else
		collect_paths(&path->all, elem);
}

t_path		*sort_paths(t_queue *start_nodes)
{
	t_path		*new;
	t_list		*lst;
	int 		idx;

	idx = 0;
	new = (t_path*)malloc(sizeof(t_path));
	IF_FAIL(new);
	new->found = start_nodes->nbr_elem;
	new->lengths = (int*)ft_memalloc(sizeof(int) * new->found);
	new->all = NULL;
	lst = start_nodes->head;
	while (lst)
	{
		f((t_table*)lst->content, new, idx++);
		lst = lst->next;
	}
	return (new);
}