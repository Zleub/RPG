/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 12:01:04 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:11:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

char		**create_map()
{
	int		i;
	int		j;
	char	**map;

	map = (char**)malloc(sizeof(char*) * MAPSIZE);
	i = 0;
	while (i < MAPSIZE)
	{
		map[i] = (char*)malloc(sizeof(char) * MAPSIZE);
		i += 1;
	}
	i = 0;
	while (i < MAPSIZE)
	{
		j = 0;
		while (j < MAPSIZE)
		{
			map[i][j] = EMPTY;
			j += 1;
		}
		i += 1;
	}
	return (map);
}

char		**new_map(int hash)
{
	char	**map;

	map = create_map();

	manage_biome_list(NEW);

	manage_hash(SET, hash);
	manage_hash(PRINT, 0);

	collect_bpoint();

	draw_mountains(map);
	draw_bpoint(map);
	fill_map(map);
	map[MAPSIZE / 2][MAPSIZE / 2] = 1;

	return (map);
}

void		print_map(char **map)
{
	int		i;
	int		j;

	if (!map)
	{
		ft_printf("no map\n");
		return ;
	}
	i = 0;
	while (i < MAPSIZE)
	{
		j = 0;
		while (j < MAPSIZE)
		{
			if (map[i][j] == -1)
				ft_printf(" \e[38;5;8mE\e[0m ");
			else if (map[i][j] == 0)
				ft_printf(" \e[38;5;0mcitadelle\e[0m ");
			else if (map[i][j] == 1)
				ft_printf(" \e[38;5;1mW\e[0m ");
			else if (map[i][j] == 2)
				ft_printf(" \e[38;5;15mF\e[0m ");
			else if (map[i][j] == 3)
				ft_printf(" \e[38;5;0mground\e[0m ");
			else if (map[i][j] == 4)
				ft_printf(" \e[38;5;112mP\e[0m ");
			else if (map[i][j] == 5)
				ft_printf(" \e[38;5;22mF\e[0m ");
			else if (map[i][j] == 6)
				ft_printf(" \e[38;5;22mF\e[0m ");
			else if (map[i][j] == 7)
				ft_printf(" \e[38;5;94mH\e[0m ");
			else if (map[i][j] == 8)
				ft_printf(" \e[38;5;252mM\e[0m ");
			else if (map[i][j] == 9)
				ft_printf(" \e[38;5;0mwater\e[0m ");
			else if (map[i][j] == 10)
				ft_printf(" \e[38;5;44mL\e[0m ");
			else if (map[i][j] == 11)
				ft_printf(" \e[38;5;25mR\e[0m ");

			j += 1;
		}
		ft_printf("\n");
		i += 1;
		}
	}

char		**manage_map(int macro, int hash)
{
	static char		**map;

	if (macro == GET)
		return (map);
	else if (macro == NEW)
		map = new_map(hash);
	else if (macro == PRINT)
		print_map(map);
	else
		ft_printf("useless call to manage_map\n");
	return (NULL);
}
