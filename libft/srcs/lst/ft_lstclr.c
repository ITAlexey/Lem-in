//
// Created by alexey on 28.10.2020.
//

#include "lists.h"

void		ft_lstclr(t_list *lst)
{
	t_list	*to_delete;

	while (lst)
	{
		to_delete = lst;
		lst = lst->next;
		free(to_delete);
	}
	to_delete = NULL;
}