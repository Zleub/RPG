#include <RPG.h>

t_biome_list		*create_biome_list(void)
{
	t_biome_list	*new;

	if (!(new = (t_biome_list*)malloc(sizeof(t_biome_list))))
		return (NULL);
	new->biome = NULL;
	new->data = -1;
	new->next = NULL;
	return (new);
}

void				print_tab(int nbr)
{
	while (nbr)
	{
		ft_printf("\t");
		nbr--;
	}
}

void				print_biome_list(t_biome_list *head, int level)
{
	if (!head)
		return ;
	print_tab(level);
	ft_printf("print_biome_list %d\n", level);
	print_tab(level);
	ft_printf("head->biome: \'%s\'\n", head->biome);
	print_biome_list(head->top, level + 1);
	print_biome_list(head->next, level);
}

int						get_lvl(char *line)
{
	int			i;

	i = 0;
	while (line[i] == '-')
		i += 1;
	return (i);
}

void					insert_next_line(int fd, t_biome_list *head, char *line)
{
	int				cmp;
	int				i;

	ft_printf("1 test de merde: %p\n", head);
	(void)fd;
	i = get_lvl(line);
	cmp = i;

	while (head->next)
	{
		head = head->next;
	}
		ft_printf("debuf: %p\n", head);

		ft_printf("debuf: %p\n", head->top);
	while (head->top && cmp)
	{
		head = head->top;
		while (head->next)
			head = head->next;
		cmp--;
	}
	ft_printf("2 test de merde: %d %p\n", i, head);
	if (i != 0)
	{
		head->top = create_biome_list();
		head->top->biome = ft_strdup(line);
	}
	else
	{
		head->next = create_biome_list();
		head->next->biome = ft_strdup(line);
	}
}

t_biome_list			*fill_biome_list(int fd)
{
	t_biome_list		*head;
	char		*line;
	// int			i;

	get_next_line(fd, &line);
	head = create_biome_list();
	head->biome = ft_strdup(line);

	while (get_next_line(fd, &line))
		insert_next_line(fd, head, line);

	return (head);
}

t_biome_list		*new_biome_list(void)
{
	t_biome_list		*head;
	int					fd;

	if (access("data/biome_list", R_OK) == -1)
		return (NULL);
	fd = open("data/biome_list", O_RDONLY);

	head = fill_biome_list(fd);

	close(fd);
	return (head);
}

t_biome_list		*manage_biome_list(int macro)
{
	static t_biome_list		*head;

	if (macro == GET)
		return (head);
	else if (macro == NEW)
		head = new_biome_list();
	else if (macro == PRINT)
		print_biome_list(head, 0);
	else
		ft_printf("useless call to manage_biome_list\n");
	return (NULL);
}
