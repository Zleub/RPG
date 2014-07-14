/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 19:33:03 by adebray           #+#    #+#             */
/*   Updated: 2014/07/08 19:35:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <basics.h>
#include <mlx.h>
// #include <math.h>

int			moveto(POINT array)
{
	managelocation("set", array);
	return (0);
}

int			lineto(POINT destination)
{
	POINT	location;

	location = managelocation("get", NULL);

	ft_printf("location: \n");
	printpoint(location);
	ft_printf("destination: \n");
	printpoint(destination);

	int x1 = location[0];
	int y1 = location[1];

	int x2 = destination[0];
	int y2 = destination[1];

	double test = round((float)(x2 - x1) / (y2 - y1));

	ft_printf("(x2 - x1): %d\n", (x2 - x1));
	ft_printf("(y2 - y1): %d\n", (y2 - y1));
	ft_printf("(x2 - x1) / (y2 - y1): %f\n", test);
	ft_printf("to int: %d\n", (int)test);

	int cmp;

	float i = location[0];
	float j = location[1];

	while (i < destination[0] + location[0] && j < destination[1] + location[1])
	{
		cmp = 0;
		while (cmp < (int)test && i + cmp < destination[0] + location[0])
		{
			ft_printf("%d. pixel put:", cmp);
			ft_printf("i: %d, j: %d\n", (int)(i + cmp), (int)j);
			mlx_pixel_put(managemlx("get"), managewin("get", NULL, NULL), (int)(i + cmp), (int)j, 0x0000ff);
			cmp += 1;
		}
		i += (int)test;
		j += 1;
	}
	return (0);
}
