#include <RPG.h>

t_biome_conf		*create_biome_conf(void)
{
	t_biome_conf	*new;

	new = (t_biome_conf*)malloc(sizeof(t_biome_conf));
	new->biome = NULL;
	new->red = -1;
	new->green = -1;
	new->blue = -1;
	new->character = -1;
	new->next = NULL;
	return (new);
}

t_biome_conf		*build_biome_conf(int fd)
{
	char			*line;
	t_biome_conf	*tmp;

	tmp = create_biome_conf();
	tmp->red = get_red(line);
}

t_biome_conf		*new_biome_conf(void)
{
	t_biome_list		*head;
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
	else
		ft_printf("Useless call to manage_biome_conf\n");
	return (NULL);
}
