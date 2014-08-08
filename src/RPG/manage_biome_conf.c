#include <RPG.h>

t_biome_conf		*create_biome_conf(void)
{
	t_biome_conf	*new;

	new = (t_biome_conf*)malloc(sizeof(t_biome_conf));
	new->biome = NULL;
	new->id = -1;
	new->color = -1;
	new->character = -1;
	new->next = NULL;
	return (new);
}

void				print_biome_conf(t_biome_conf *ptr)
{
	if (ptr)
	{
		dprintf(2, "\nprint_biome_conf: \n");
		dprintf(2, "ptr->biome: %s\n", ptr->biome);
		dprintf(2, "ptr->id: %d\n", ptr->id);
		dprintf(2, "ptr->color: %d\n", ptr->color);
		dprintf(2, "ptr->character: %c\n", ptr->character);
		print_biome_conf(ptr->next);
	}
}

char				*bget_name(char *line)
{
	int				i;

	i = 0;
	while (!ft_isspace(line[i]))
		i += 1;
	return (ft_strndup(line, i));
}

int					bget_color(char *line)
{
	int				i;

	i = 0;
	while (line[i] != '{')
		i += 1;
	return (ft_atoi(line + i + 1));
}

char				bget_character(char *line)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		i += 1;
		while (line[i] != ',')
			i += 1;
		j += 1;
	}
	return (*(line + i + j - 1));
}

int					bget_id(char *name)
{
	t_biome_list	*ptr1;
	t_biome_list	*ptr2;
	t_biome_list	*head;

	(void)name;
	head = manage_biome_list(GET);

	while (head)
	{
		ptr1 = head;
		while (ptr1)
		{
			ptr2 = ptr1;
			while (ptr2)
			{
				if (!ft_strcmp(ptr2->biome, name))
					return (ptr2->id);
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->top;
		}
		head = head->next;
	}
	return (-1);
}

void				fill_biome_conf(t_biome_conf *ptr, char *line)
{
	ptr->biome = bget_name(line);
	ptr->id = bget_id(ptr->biome);
	ptr->color = bget_color(line);
	ptr->character = bget_character(line);
}

t_biome_conf		*build_biome_conf(int fd)
{
	char			*line;
	t_biome_conf	*head;
	t_biome_conf	*tmp;

	get_next_line(fd, &line);
	head = create_biome_conf();
	fill_biome_conf(head, line);

	tmp = head;
	while (get_next_line(fd, &line) > 0)
	{
		tmp->next = create_biome_conf();
		fill_biome_conf(tmp->next, line);
		tmp = tmp->next;
	}

	return (head);
}

t_biome_conf		*new_biome_conf(void)
{
	t_biome_conf		*head;
	int					fd;

	if (access("data/biome_conf", R_OK) == -1)
		return (NULL);
	fd = open("data/biome_conf", O_RDONLY);

	head = build_biome_conf(fd);

	close(fd);
	return (head);
}

t_biome_conf		*manage_biome_conf(int macro)
{
	static t_biome_conf	*head;

	if (macro == GET)
		return (head);
	else if (macro == NEW)
		head = new_biome_conf();
	else if (macro == PRINT)
		print_biome_conf(head);
	else
		ft_printf("Useless call to manage_biome_conf\n");
	return (NULL);
}
