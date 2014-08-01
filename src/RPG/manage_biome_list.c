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

int						get_lvl(char *line)
{
	int			i;

			i = 0;
		while (line[i] == '-')
			i += 1;
		return (i);
}

t_biome_list			*get_prev(t_biome_list *head, int lvl)
{
	while (head->next)
		head = head->next;
	if (lvl && head->top)
		return (get_prev(head->top, lvl - 1));
	else
		return (head);
}

t_biome_list			*fill_biome_list(int fd)
{
	t_biome_list		*head;
	char		*line;
	int			i;

	get_next_line(fd, &line);
	head = create_biome_list();
	head->biome = ft_strdup(line);

	t_biome_list *tmp;
	i = 0;

	while (get_next_line(fd, &line))
	{
		i = get_lvl(line);
		tmp = get_prev(head, i);

		ft_printf("%d, %p: %s\n", i, tmp, tmp->biome);
	}
	(void)tmp;
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
