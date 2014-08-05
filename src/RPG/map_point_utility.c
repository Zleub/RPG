/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 20:55:40 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 20:57:02 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

void		draw_bpoint(char **map)
{
	t_bpoint_list	*ptr;

	ptr = manage_bpoint_list(GET, NULL);
	while (ptr)
	{
		map[ptr->x][ptr->y] = ptr->id;
		if (ptr->type == CIRCLE)
		{
			if (ptr->id < 10) //Ground
				draw_disk(map, ptr->x, ptr->y, 3);
			else
				draw_disk(map, ptr->x, ptr->y, 1);
		}
		ptr = ptr->next;
	}
}

int		count_gpoint(t_biome_list *ptr)
{
	int i = 0;
	while (ptr)
	{
		if (ptr->data == LINE || ptr->data == CIRCLE)
			i += 1;
		ptr = ptr->next;
	}
	return (i);
}

t_biome_list	*get_biome_ptr(char *str)
{
	t_biome_list	*ptr;

	ptr = manage_biome_list(GET);
	while (ptr && ft_strcmp(ptr->biome, str))
		ptr = ptr->next;
	return (ptr);
}

int				count_biome_top(t_biome_list *ptr)
{
	int			i;

	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i += 1;
	}
	return (i);
}
