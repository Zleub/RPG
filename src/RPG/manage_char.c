/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 11:55:49 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 17:43:10 by adebray          ###   ########.fr       */
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
	new->initial_hash = -1;
	new->hash = -1;

	new->strength = -1;
	new->stamina = -1;
	new->agility = -1;
	new->dexterity = -1;
	new->intelligence = -1;
	new->charisma = -1;
	new->wisdom = -1;
	new->will = -1;

	new->life = -1;
	new->id = -1;
	new->cmp = -1;
	new->ticks = -1;
	new->age = -1;
	new->job = NULL;
	new->state = NULL;
	return (new);
}

// void				print_heros(t_heros *character)
// {
// 	printf("print_heros\n");
// 	printf("name: %s\n", character->name);
// 	printf("location: %s\n", character->location);
// 	printf("level: %d\n", character->level);
// 	printf("experience: %d\n", character->experience);
// 	printf("strengh: %d\n", character->strengh);
// 	printf("armor: %d\n", character->armor);
// 	printf("life: %d\n", character->life);
// }

// void				wprint_heros()

// void				save_heros(t_heros *character)
// {
// 	int				fd;

// 	fd = open(character->name, O_CREAT | O_TRUNC | O_WRONLY);
// 	ft_putstr_fd(character->name, fd);
// 	write(fd, "\n", 1);
// 	ft_putstr_fd(character->location, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(character->level, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(character->experience, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(character->strengh, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(character->armor, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(character->life, fd);
// 	write(fd, "\n", 1);
// 	close(fd);
// }

// t_heros				*load_heros(STRING name)
// {
// 	t_heros			*new;
// 	int				fd;
// 	int				i;
// 	STRING			line;

// 	if ((fd = open(name, O_RDONLY)) == -1)
// 	{
// 		printf("Heros unknown\n");
// 		return (NULL);
// 	}
// 	else
// 	{
// 		printf("OK: %d\n", fd);
// 		i = 0;
// 		new = create_heros();
// 		while (get_next_line(fd, &line) > -1 && i < LIFE + 1)
// 		{
// 			if (i == NAME)
// 				new->name = ft_strdup(line);
// 			if (i == LOCATION)
// 				new->location = ft_strdup(line);
// 			if (i == LEVEL)
// 				new->level = ft_atoi(line);
// 			if (i == EXPERIENCE)
// 				new->experience = ft_atoi(line);
// 			if (i == STRENGH)
// 				new->strengh = ft_atoi(line);
// 			if (i == ARMOR)
// 				new->armor = ft_atoi(line);
// 			if (i == LIFE)
// 				new->life = ft_atoi(line);
// 			i += 1;
// 		}
// 		close (fd);
// 	}
// 	return (new);
// }

int					update_char_hash(t_heros *elem, int diviser)
{
	int				tmp;

	tmp = elem->hash % diviser;
	if (elem->hash / diviser <= 5381)
		elem->hash = elem->hash / diviser ^ ;
	else
		elem->hash = elem->hash / diviser;
	return (tmp);
}

t_heros				*new_char(STRING str)
{
	t_heros			*new;
	static int		cmp;

	new = create_heros();
	new->name = ft_strdup(str);
	new->location = "Wilderness";
	new->initial_hash = ft_hash(str);
	new->hash = ft_hash(str);
	new->experience = 0;
	new->level = 0;
	new->strength = 0;
	new->stamina = 0;
	new->agility = 0;
	new->dexterity = 0;
	new->intelligence = 0;
	new->charisma = 0;
	new->wisdom = 0;
	new->will = 0;
	new->life = 20;
	new->id = cmp;
	new->cmp = 0;
	new->ticks = 0;
	new->age = 15;
	new->state = manage_calendar(GET);
	new->job = "rover";
	manage_heros_list(ADD, new);
	cmp += 1;
	return (new);
}

t_heros		*manage_char(int macro, STRING name)
{
	static t_heros		*heros;

	if (macro == GET)
		return (heros);
	// else if (macro == SET)
	// 	heros = new_heros;
	// else if (macro == LOAD)
	// 	load_heros(name);
	else if (macro == NEW)
		new_char(name);
	else
		ft_printf("useless call to manage_char\n");
	return (NULL);
}
