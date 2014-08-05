/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mountains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 21:01:09 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:05:27 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

char		**create_mountains(void)
{
	int		x;
	int		y;
	int		wpt;
	char	**mountains;

	mountains = create_map();
	wpt = manage_hash(GET, 3) + MAPSIZE / 5;
	while (wpt)
	{
		x = manage_hash(GET, MAPSIZE);
		y = manage_hash(GET, MAPSIZE);
		mountains[x][y] = 1;

		draw_disk(mountains, x, y, MAPSIZE / 3);
		wpt -= 1;
	}
	return (mountains);
}

void			change_empty(char **map)
{
	int o = 0;
	while (o < MAPSIZE)
	{
		int p = 0;
		while (p < MAPSIZE)
		{
			if (map[o][p] == EMPTY)
				map[o][p] = 0;
			p += 1;
		}
		o += 1;
	}
}

void		draw_mountains(char **map)
{
	t_biome_list	*tmp;
	t_biome_list	*ptr;
	char			**mountains;

	mountains = create_mountains();

	ptr = get_biome_ptr("ground");

	tmp = ptr->top;
	while (ft_strcmp(tmp->biome, "Mountain"))
		tmp = tmp->next;

	change_empty(mountains);
	write_mountains(map, mountains, tmp->id);
}
