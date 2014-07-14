/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:39:53 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/09 21:50:51 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#include <libft.h>
#include <ft_printf.h>
#include <basics.h>
#include <mlx.h>

void	create_thread(int i);

void	test_main(void)
{
	while (1)
		usleep(500);
	return ;
}

void	create_thread(int i)
{
	pthread_t *thread;

	thread = (pthread_t*)malloc(sizeof(pthread_t));
	pthread_create(thread, NULL, (void *)test_main, NULL);
	if (i != 1)
		create_thread(i - 1);
	else
		pthread_join(*thread, NULL);

}

#include <stdio.h>

void	drawcirc(int r)
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*image;
	int		bits_per_pixel = 0;
	int		line_size = 0;
	int		endian = 0;

	mlx_ptr = managemlx("get");
	img_ptr = manageimage("set", makepoint(r * 2 + 1, r * 2 + 1));

	image = mlx_get_data_addr(img_ptr, &bits_per_pixel, &line_size, &endian);

	int *prout = (int*)(image);


	int		i = 0;
	int j = 0;

	int margin = r - (r / 2);
	int color = managecolor("get", 0);
	while (i < (r * 2 + 1) * (r * 2 + 1))
	{
		j = 0;
		while (j < line_size)
		{
			if (j > 0 + margin && j < line_size / 4 - margin)
			{
				*(prout + j) = mlx_get_color_value(mlx_ptr, color);
			}
			else if (j > line_size / 4 + margin && j < line_size / 4 - margin)
			{
				*(prout + j) = mlx_get_color_value(mlx_ptr, color);
			}
			else if (j > line_size / 2 + margin && j < line_size / 2 - margin)
			{
				*(prout + j) = mlx_get_color_value(mlx_ptr, color);
			}
			else if (j > line_size - line_size / 4 + margin && j < line_size - line_size / 4 - margin)
			{
				*(prout + j) = mlx_get_color_value(mlx_ptr, color);
			}

			if (i < ((r * 2 + 1) * (r * 2 + 1) / 2))
			{
				if (j == line_size / 4 || j == line_size / 2 || j == line_size - line_size / 4)
					margin -= 1;
			}
			else
			{
				if (j == line_size / 4 || j == line_size / 2 || j == line_size - line_size / 4)
					margin += 1;
			}

			printf("test: %d\n", j);
			j += 1;
		}
		// margin += 1;
		// j = line_size / 4;
		// while (j < line_size / 2)
		// {
		// 	if (j > line_size / 4 + margin && j < line_size / 4 + margin)
		// 	{
		// 		*(prout + j) = mlx_get_color_value(mlx_ptr, color);
		// 	}
		// 	printf("test: %d\n", j);
		// 	j += 1;
		// }
		// margin += 1;
		// j = line_size / 2;
		// while (j < line_size - line_size / 4)
		// {
		// 	if (j > r - (r / 2) && j < (r * 2 + 1) - (r - (r / 2)))
		// 	{
		// 		*(prout + j) = mlx_get_color_value(mlx_ptr, color);
		// 	}
		// 	printf("test: %d\n", j);
		// 	j += 1;
		// }
		// margin += 1;
		// j = line_size - line_size / 4;
		// while (j < line_size)
		// {
		// 	if (j > r - (r / 2) && j < (r * 2 + 1) - (r - (r / 2)))
		// 	{
		// 		*(prout + j) = mlx_get_color_value(mlx_ptr, color);
		// 	}
		// 	printf("test: %d\n", j);
		// 	j += 1;
		// }






		prout += line_size;
		i += line_size;
	}
	manageimage("screen", NULL);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = managemlx("set");
	win_ptr = managewin("set", makepoint(420, 420), "42");

	managecolor("set", 0xff0000);

	moveto(makepoint(10, 10));
	drawrect(makepoint(256,256));

	managecolor("set", 0x00ff00);


	moveto(makepoint(50, 50));
	drawcirc(60);

	while (42)
	{
		usleep(100);
	}

	// philo_main();
	return (0);
}
