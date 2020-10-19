//
// Created by alexey on 17.10.2020.
//

#include "ant_farm.h"

void 	add_neighbors(t_queue *q, t_list *neighbors)
{
	t_list	*tmp;
	t_room	*neighbor;

	tmp = neighbors;
	while (tmp)
	{
		neighbor = (t_room*)((t_table*)tmp->content)->value;
		if (!neighbor->is_visited)
		{
			neighbor->is_visited = true;
			enqueue(q, tmp->content);
		}
		tmp = tmp->next;
	}
}

bool 	bfs(t_farm *data, char *start_room)
{
	t_queue		*q;
	t_table		*current;
	bool 		ret;

	ret = false;
	q = init_queue();
	enqueue(q, (void*)get_table(data->rooms, start_room));
	while (!is_empty(q))
	{
		current = (t_table*)dequeue(q);
		add_neighbors(q, ((t_room*)current->value)->neighbors);
	}
	remove_queue(q);
	return (ret);
}