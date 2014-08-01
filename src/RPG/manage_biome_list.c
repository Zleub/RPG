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

t_biome_list		*new_biome_list(void)
{
	int					fd;
	char				*buffer;
	t_biome_list		*head;
	t_biome_list		*tmp;

	if (access("data/biome_list", R_OK) == -1)
		return (NULL);
	fd = open("data/biome_list", O_RDONLY);


	get_next_line(fd, &buffer);


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
	else
		ft_printf("useless call to manage_biome_list\n");
	return (NULL);
}
