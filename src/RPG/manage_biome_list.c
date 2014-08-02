#include <RPG.h>

t_biome_list		*create_biome_list(void)
{
	t_biome_list	*new;
	static int		cmp;

	if (!(new = (t_biome_list*)malloc(sizeof(t_biome_list))))
		return (NULL);
	new->biome = NULL;
	new->data = -1;
	new->next = NULL;
	new->top = NULL;
	new->id = cmp;
	cmp += 1;
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
	// print_tab(level);
	// ft_printf("print_biome_list %d\n", level);
	print_tab(level);
	ft_printf("%s: %d\n", head->biome, head->data);
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

char					*ft_extract(char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != ':')
	{
		if (line[i] == '-')
			j += 1;
		i += 1;
	}
	if (j)
		j += 1;
	return (ft_strndup(line + j, i - j));
}

int					ft_check(char *line)
{
	int			i;

	i = 0;
	while (line[i] && line[i] != ':')
		i += 1;
	if (i < (int)ft_strlen(line))
	{
		if (!ft_strcmp(&line[i + 2], "empty"))
			return (EMPTY);
		else if (!ft_strcmp(&line[i + 2], "unique"))
			return (UNIQUE);
		else if (!ft_strcmp(&line[i + 2], "fill"))
			return (FILL);
		else if (!ft_strcmp(&line[i + 2], "circle"))
			return (CIRCLE);
		else if (!ft_strcmp(&line[i + 2], "rect"))
			return (RECT);
		else if (!ft_strcmp(&line[i + 2], "line"))
			return (LINE);
	}
	return (-1);
}

void					insert_next_line(t_biome_list *head, char *line)
{
	int				i;

	i = get_lvl(line);
	while (head->next)
	{
		head = head->next;
	}
	while (head->top && i)
	{
		head = head->top;
		while (head->next)
			head = head->next;
		i--;
	}
	if (i != 0)
	{
		head->top = create_biome_list();
		head->top->biome = ft_extract(line);
		head->top->data = ft_check(line);
	}
	else
	{
		head->next = create_biome_list();
		head->next->biome = ft_extract(line);
		head->next->data = ft_check(line);
	}
}

t_biome_list			*fill_biome_list(int fd)
{
	t_biome_list		*head;
	char		*line;
	// int			i;

	get_next_line(fd, &line);
	head = create_biome_list();
	head->biome = ft_extract(line);

	while (get_next_line(fd, &line))
		insert_next_line(head, line);

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
