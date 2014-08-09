/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 20:52:09 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 06:52:03 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

void		new_point(t_biome_tree *tmp)
{
	int		x;
	int		y;

	x = manage_hash(GET, MAPSIZE);
	y = manage_hash(GET, MAPSIZE);
	manage_bpoint_list(NEW, create_wintab(x, y, tmp->id, tmp->data));
}

void		collect_wpoint()
{
	t_biome_tree	*ptr;
	t_biome_tree	*tmp;
	int				biome_rand;
	int				i;

	ptr = get_biome_ptr("water");
	i = count_biome_top(ptr->top);
	biome_rand = manage_hash(GET, i);
	dprintf(2, "Wbiome_rand %d\n", biome_rand);

	tmp = ptr->top;
	i = biome_rand;
	while (i--)
		tmp = tmp->next;
	new_point(tmp);
}

void		collect_gpoint()
{
	t_biome_tree	*ptr;
	t_biome_tree	*tmp;
	int				i;
	int				biome_rand;

	ptr = get_biome_ptr("ground");
	i = count_gpoint(ptr->top);
	biome_rand = manage_hash(GET, i);
	tmp = ptr->top;
	while (tmp->data != LINE && tmp->data != CIRCLE)
		tmp = tmp->next;
	while (biome_rand)
	{
		if (tmp == NULL)
			tmp = ptr->top;
		tmp = tmp->next;
		while (tmp->data != LINE && tmp->data != CIRCLE)
		{
			tmp = tmp->next;
		}
		biome_rand -= 1;
	}
	dprintf(2, "return: %s\n", tmp->biome);
	new_point(tmp);
}

void		collect_bpoint()
{
	int				wpt;

	wpt = manage_hash(GET, 6) + MAPSIZE / 10;
	while (wpt)
	{
		collect_wpoint();
		wpt -= 1;
	}
	wpt = manage_hash(GET, 6) + MAPSIZE / 5;
	while (wpt)
	{
		dprintf(2, "Collect gpoint\n");
		collect_gpoint();
		wpt -= 1;
	}
}
