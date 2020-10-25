//
// Created by alexey on 24.10.2020.
//

void 	print_path(t_hashmap *rooms, t_room *end)
{
	t_room *tmp;

	tmp = end;
	printf("%s", "H");
	while (tmp->member != NULL)
	{
		printf("<-%s", tmp->member);
		tmp = get_elem(rooms, tmp->member);
	}
	printf("\n");

}

void 	print_list(t_list *lst, char name[])
{
	t_connection *tmp;
	t_list		*cur;

	cur = lst;
	printf("%s  :", name);
	while (cur)
	{
		tmp = cur->content;
		printf("[%s %d]", tmp->room_name, tmp->flow);
		if (cur->next)
			printf(" -> ");
		cur = cur->next;
	}
	printf("\n\n");
}

void 	print_neighbors(t_hashmap *rooms)
{
	t_table *h;
	t_table *a;
	t_table *d;
	t_table *e;

	h = get_table(rooms, "H");
	a = get_table(rooms, "A");
	d = get_table(rooms, "D");
	e = get_table(rooms, "E");
	print_list(((t_room*)h->value)->neighbors, "H");
	print_list(((t_room*)a->value)->neighbors, "A");
	print_list(((t_room*)d->value)->neighbors, "D");
	print_list(((t_room*)e->value)->neighbors, "E");
}