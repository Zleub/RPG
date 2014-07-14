/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 12:24:13 by adebray           #+#    #+#             */
/*   Updated: 2014/07/01 19:31:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

int			*makepoint(int x, int y)
{
	POINT	new_array;

	new_array = malloc(sizeof(int) * 2);
	new_array[0] = x;
	new_array[1] = y;
	managepointlist("add", new_array);
	return (new_array);
}

void		printpoint(POINT array)
{
	if (array)
	{
		ft_printf("printpoint: \n");
		ft_printf("array[0]: %d\n", array[0]);
		ft_printf("array[1]: %d\n", array[1]);
	}
	else
		ft_printf("no point\n");
}
