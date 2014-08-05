#include <RPG.h>

t_bpoint_list	*create_bpoint_list(void)
{
	t_bpoint_list	*elem;

	if (!(elem = (t_bpoint_list*)malloc(sizeof(t_bpoint_list))))
		return (NULL);
	elem->x = -1;
	elem->y = -1;
	elem->id = -1;
	elem->type = -1;
	elem->next = NULL;
	return (elem);
}

t_bpoint_list	*new_bpoint_list(WINTAB *array)
{
	t_bpoint_list	*head;
	t_bpoint_list	*elem;
	t_bpoint_list	*tmp;

	head = manage_bpoint_list(GET, NULL);
	if (!head)
	{
		elem = create_bpoint_list();
		elem->x = array[0];
		elem->y = array[1];
		elem->id = array[2];
		elem->type = array[3];
		return (elem);
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		elem = create_bpoint_list();
		elem->x = array[0];
		elem->y = array[1];
		elem->id = array[2];
		elem->type = array[3];
		tmp->next = elem;
		return (head);
	}
}

void			print_bpoint_list(t_bpoint_list *head)
{
	if (head)
	{
		ft_printf("print_bpoint_list: \n");
		ft_printf("x: %d\n", head->x);
		ft_printf("y: %d\n", head->y);
		ft_printf("id: %d\n", head->id);
		ft_printf("type: %d\n", head->type);
		print_bpoint_list(head->next);
	}
}

t_bpoint_list	*manage_bpoint_list(int macro, WINTAB *array)
{
	static t_bpoint_list		*head;

	if (macro == GET)
		return (head);
	else if (macro == NEW)
		head = new_bpoint_list(array);
	else if (macro == PRINT)
		print_bpoint_list(head);
	else
		ft_printf("useless call to manage_bpoint_list\n");
	return (NULL);
}
