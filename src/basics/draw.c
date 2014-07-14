/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/01 19:37:14 by adebray           #+#    #+#             */
/*   Updated: 2014/07/09 00:47:07 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

int			drawpix(POINT pix)
{
	mlx_pixel_put(managemlx("get"), managewin("get", NULL, NULL), pix[0], pix[1], managecolor("get", 0));
	return (0);
}

int			drawrect(POINT size)
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*image;
	int		bits_per_pixel = 0;
	int		line_size = 0;
	int		endian = 0;

	mlx_ptr = managemlx("get");
	img_ptr = manageimage("set", size);

	image = mlx_get_data_addr(img_ptr, &bits_per_pixel, &line_size, &endian);

	int *prout = (int*)(image);

	int i = 0;
	int j = 0;

	int color = managecolor("get", 0);
	while (i < size[0] * size[1])
	{
		j = 0;
		while (j < line_size)
		{
			*(prout + j) = mlx_get_color_value (mlx_ptr, color);
			j += 1;
		}
		prout += line_size;
		i += line_size;
	}
	manageimage("screen", NULL);
	return (0);
}
