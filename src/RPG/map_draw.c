/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 20:59:38 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:06:34 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

void			draw_disk(char **map, int x, int y, int bonus)
{
	int i;
	int j;
	int q;

	q = manage_hash(GET, 3) + bonus;
	j = -q;
	while (j <= q)
	{
		i = -q;
		while (i <= q)
		{
			if( i*i + j*j <= q * q + q * 0.8f
				&& i + y >= 0 && i + y < MAPSIZE
				&& j + x >= 0 && j + x < MAPSIZE
				&& map[j + x][i + y] == EMPTY)
			{
				map[j + x][i + y] = map[x][y];
			}
			i += 1;
		}
		j += 1;
	}
}

void		fill_map(char **map)
{
	int				a;
	int				b;
	t_biome_list	*ptr;
	t_biome_list	*tmp;

	ptr = get_biome_ptr("ground");

	tmp = ptr->top;
	while (tmp->data != FILL)
		tmp = tmp->next;

	a = 0;
	while (a < MAPSIZE)
	{
		b = 0;
		while (b < MAPSIZE)
		{
			if (map[a][b] == EMPTY)
				map[a][b] = tmp->id;
			b += 1;
		}
		a += 1;
	}
}

void		write_mountains(char **map, char **mountains, int biome_id)
{
	int		o;
	int		p;

	o = 0;
	p = 0;
	while (o < MAPSIZE)
	{
		p = 0;
		while (p < MAPSIZE)
		{
			if ((o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
					&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1])
				|| (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
				&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
				|| (o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
					&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
				|| (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
					&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1]))
			{
				map[o][p] = biome_id;
			}
			p += 1;
		}
		o += 1;
	}
}
