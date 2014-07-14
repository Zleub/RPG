/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/01 19:42:34 by adebray           #+#    #+#             */
/*   Updated: 2014/07/09 05:03:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

void		*managemlx(char *macro)
{
	static void		*mlx_ptr;

	if (!strcmp(macro, "set"))
	{
		mlx_ptr = mlx_init();
		return (mlx_ptr);
	}
	else if (!strcmp(macro, "get"))
	{
		if (!mlx_ptr)
			return (NULL);
		else
			return (mlx_ptr);
	}
	return (NULL);
}

void		*managewin(char *macro, POINT size, char *name)
{
	static void		*win_ptr;

	if (!strcmp(macro, "set"))
	{
		win_ptr = mlx_new_window(managemlx("get"), size[0], size[1], name);
		return (win_ptr);
	}
	else if (!strcmp(macro, "get"))
	{
		if (!win_ptr)
			return (NULL);
		else
			return (win_ptr);
	}
	return (NULL);
}

POINT		managelocation(char *macro, POINT value)
{
	static POINT	location;

	if (!strcmp(macro, "set"))
	{
		location = value;
		return (location);
	}
	else if (!strcmp(macro, "get"))
	{
		if (!location)
			return (NULL);
		else
			return (location);
	}
	else
		ft_printf("Useless managelocation call\n");
	return (NULL);
}

int			managecolor(char *macro, int value)
{
	static int	color;

	if (!strcmp(macro, "set"))
	{
		color = value;
		return (color);
	}
	else if (!strcmp(macro, "get"))
	{
		if (!color)
			return (0);
		else
			return (color);
	}
	else
		ft_printf("Useless managecolor call\n");
	return (0);
}

char		*manageimage(char *macro, POINT value)
{
	POINT		location;
	void			*win_ptr;
	void			*mlx_ptr;
	static void	*img_ptr;

	if (!strcmp(macro, "set"))
	{
		if ((location = managelocation("get", NULL)) != NULL
			&& (mlx_ptr = managemlx("get")) != NULL
			&& (win_ptr = managewin("get", NULL, NULL)) != NULL)
		{
			img_ptr = mlx_new_image (mlx_ptr, value[0], value[1]);
			return (img_ptr);
		}
	}
	else if (!strcmp(macro, "get"))
	{
		if (!img_ptr)
			return (NULL);
		else
			return (img_ptr);
	}
	else if (!strcmp(macro, "screen"))
	{
		if (!img_ptr)
			ft_printf("no image to screen\n");
		else
		{
			if ((location = managelocation("get", NULL)) != NULL
				&& (mlx_ptr = managemlx("get")) != NULL
				&& (win_ptr = managewin("get", NULL, NULL)) != NULL
				&& img_ptr != NULL)
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, location[0], location[1]);
				mlx_destroy_image(mlx_ptr, img_ptr);
				img_ptr = NULL;
			}
		}
	}
	else
		ft_printf("Useless manageimage call\n");
	return (NULL);
}
