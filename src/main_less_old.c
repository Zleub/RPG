/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/03 04:39:53 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/14 01:00:50 by Arno             ###   ########.fr       */
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

void	imagecirc(int *center, int line_size, int r)
{
	int			color;
	int			i;
	void		*mlx_ptr;
	POINT		location;

	ft_printf("r: %d, center: %p\n", r, center);
	if (!(location = managelocation("get", NULL))
		|| !(mlx_ptr = managemlx("get"))
		|| !(color = managecolor("get", 0)))
			return ;
	i = 0;
	while (i <= r)
	{
		*(center + 1 * i) = mlx_get_color_value(mlx_ptr, color);
		*(center - 1 * i) = mlx_get_color_value(mlx_ptr, color);
		*(center) = mlx_get_color_value(mlx_ptr, color);
		*(center + (line_size / 4) * i) = mlx_get_color_value(mlx_ptr, color);
		*(center - (line_size / 4) * i) = mlx_get_color_value(mlx_ptr, color);
		i += 1;
	}
}

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

	int *adress = (int*)(image);

	imagecirc(adress + ((r * 2 + 1) * (r * 2 + 1)) / 2, line_size, r);

	manageimage("screen", NULL);
}

#include <fcntl.h>

int		main(void)
{
	// void	*mlx_ptr;
	// void	*win_ptr;

	// mlx_ptr = managemlx("set");
	// win_ptr = managewin("set", makepoint(420, 420), "42");

	// managecolor("set", 0xff0000);

	// moveto(makepoint(10, 10));
	// drawrect(makepoint(256,256));

	// managecolor("set", 0x00ff00);


	// moveto(makepoint(50, 50));
	// drawcirc(5);

	// moveto(makepoint(70, 70));
	// drawcirc(20);



	// while (42)
	// {
	// 	usleep(100);
	// }

	int fd;
	char *str;
	fd = open("Untitled.png", O_RDONLY);
	while (get_next_line(fd, &str) > -1)
	{
		int i = 0;
		while (str[i])
		{
			ft_printf("%d", str[i]);
			i += 1;
		}
		ft_printf("\n");
	}

	// philo_main();
	return (0);
}
