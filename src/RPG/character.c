/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 11:55:49 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 03:58:14 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_heros				*create_heros(void)
{
	t_heros			*new;

	if (!(new = (t_heros*)malloc(sizeof(t_heros))))
		return (NULL);
	new->name = NULL;
	new->location = NULL;
	new->level = -1;
	new->experience = -1;
	new->strengh = -1;
	new->armor = -1;
	new->life = -1;
	return (new);
}

void				print_heros(t_heros *character)
{
	printf("print_heros\n");
	printf("name: %s\n", character->name);
	printf("location: %s\n", character->location);
	printf("level: %d\n", character->level);
	printf("experience: %d\n", character->experience);
	printf("strengh: %d\n", character->strengh);
	printf("armor: %d\n", character->armor);
	printf("life: %d\n", character->life);
}

// void				wprint_heros()

void                save_heros(t_heros *character)
{
	int             fd;

	fd = open(character->name, O_CREAT | O_TRUNC | O_WRONLY);
	ft_putstr_fd(character->name, fd);
	write(fd, "\n", 1);
	ft_putstr_fd(character->location, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(character->level, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(character->experience, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(character->strengh, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(character->armor, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(character->life, fd);
	write(fd, "\n", 1);
	close(fd);
}

t_heros            *load_heros(STRING name)
{
	t_heros        *new;
	int            fd;
	int            i;
	STRING         line;

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		printf("Heros unknown\n");
		return (NULL);
	}
	else
	{
		printf("OK: %d\n", fd);
		i = 0;
		new = create_heros();
		while (get_next_line(fd, &line) > -1 && i < LIFE + 1)
		{
			if (i == NAME)
				new->name = ft_strdup(line);
			if (i == LOCATION)
				new->location = ft_strdup(line);
			if (i == LEVEL)
				new->level = ft_atoi(line);
			if (i == EXPERIENCE)
				new->experience = ft_atoi(line);
			if (i == STRENGH)
				new->strengh = ft_atoi(line);
			if (i == ARMOR)
				new->armor = ft_atoi(line);
			if (i == LIFE)
				new->life = ft_atoi(line);
			i += 1;
		}
		close (fd);
	}
	return (new);
}
