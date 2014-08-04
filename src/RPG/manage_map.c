#include <RPG.h>
#include <limits.h>

char		**create_map()
{
	int		i;
	int		j;
	char	**map;

	map = (char**)malloc(sizeof(char*) * MAPSIZE);
	i = 0;
	while (i < MAPSIZE)
	{
		map[i] = (char*)malloc(sizeof(char) * MAPSIZE);
		i += 1;
	}
	i = 0;
	while (i < MAPSIZE)
	{
		j = 0;
		while (j < MAPSIZE)
		{
			map[i][j] = EMPTY;
			j += 1;
		}
		i += 1;
	}
	return (map);
}

size_t		update_hash(size_t hash, int diviser)
{
	ft_printf("if %d (hash) / %d (diviser) = %d <= 5381\n", hash, diviser, hash /diviser);
	if (hash / diviser <= 5381)
	{
		ft_printf("return %d\n", INT_MAX - hash / diviser);
		return (INT_MAX - hash / diviser);
	}
	else
		return (hash / diviser);
}

void		print_hash(int hash)
{
	ft_printf("print_hash: %d\n", hash);
}

int		manage_hash(int macro, int nbr)
{
	int				tmp;
	static int		hash;
	static int		initial;

	if (macro == GET)
	{
		if (hash / nbr <= 5381)
		{
			// ft_printf("1.1 %d\n", hash);
			hash = hash / nbr ^ initial;
			// ft_printf("1.2 %d\n", hash);
		}
		else
		{
			// ft_printf("2.1 %d\n", hash / nbr);
			hash = hash / nbr;
			// ft_printf("2.2 %d\n", hash / nbr);
		}
		tmp = hash % nbr;
		return (tmp);
	}
	else if (macro == SET)
	{
		hash = nbr;
		initial = nbr;
	}
	else if (macro == PRINT)
		print_hash(hash);
	else
		ft_printf("useless call to manage_hash\n");
	return (0);
}

int		ft_abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (x * -1);
}

void		print_array(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAPSIZE)
	{
		j = 0;
		while (j < MAPSIZE)
		{
			ft_printf(" %d", map[i][j]);
			j += 1;
		}
		ft_printf("\n");
		i += 1;
	}

}

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

// int			draw_line(char **map, int x, int y, int nbr)
// {
// 	int q = nbr % 3;
// 	nbr = update_hash(nbr, 3);
// 	ft_printf("q: %d\n", q);
// 	ft_printf("draw_disk: x %d, y %d\n", x, y);
// }

void		light_on(char **map, int x, int y)
{
	// if (x + 1 < MAPSIZE && y + 1 < MAPSIZE)
	map[x][y] = 2;
}

void		collect_bpoint()
{

}

char		**new_map(int hash)
{
	int		x;
	int		y;
	char	**map;

	map = create_map();

	manage_biome_list(NEW);
	// manage_biome_list(PRINT);


	manage_hash(SET, hash);
	manage_hash(PRINT, 0);


	int wpt = manage_hash(GET, 6) + 3;
	ft_printf("wpt-> %d\n", wpt);

	t_biome_list *ptr;

	while (wpt)
	{
		ptr = manage_biome_list(GET);
		while (ptr && ft_strcmp(ptr->biome, "water"))
			ptr = ptr->next;

		int i;
		t_biome_list *tmp = ptr->top;
		i = 0;
		while (tmp)
		{
			tmp = tmp->next;
			i += 1;
		}

		int biome_rand = manage_hash(GET, i);

		tmp = ptr->top;
		i = biome_rand;
		while (i--)
			tmp = tmp->next;

		x = manage_hash(GET, MAPSIZE);
		y = manage_hash(GET, MAPSIZE);
		map[x][y] = tmp->id;

		// ft_printf("%s\n", tmp->biome);

		if (tmp->data == CIRCLE)
			draw_disk(map, x, y, 3);
		// else if (tmp->data == LINE)
			// nbr = draw_line(map, x, y, nbr);
		wpt -= 1;
	}

	wpt = manage_hash(GET, 6) + 6;

	while (wpt)
	{
		ptr = manage_biome_list(GET);
		while (ptr && ft_strcmp(ptr->biome, "ground"))
			ptr = ptr->next;

		t_biome_list *tmp = ptr->top;
		int i = 0;
		while (tmp)
		{
			if (tmp->data == LINE || tmp->data == CIRCLE)
				i += 1;
			tmp = tmp->next;
		}

		int biome_rand = manage_hash(GET, i);

		tmp = ptr->top;
		i = biome_rand;

		// ft_printf("ground: %d\n", i);

		while (tmp->data != LINE && tmp->data != CIRCLE)
			tmp = tmp->next;
		while (i)
		{
			while (tmp->data != LINE && tmp->data != CIRCLE)
				tmp = tmp->next;
			tmp = tmp->next;
			i -= 1;
		}

		x = manage_hash(GET, MAPSIZE);
		y = manage_hash(GET, MAPSIZE);
		map[x][y] = tmp->id;

		// ft_printf("%s\n", tmp->biome);

		if (tmp->data == CIRCLE)
			draw_disk(map, x, y, 1);
		// else if (tmp->data == LINE)
			// nbr = draw_line(map, x, y, nbr);
		wpt -= 1;

	}

	char **mountains;

	mountains = create_map();

	wpt = manage_hash(GET, 3) + 1;
	ft_printf("this is nbr : %d\n", wpt);
	while (wpt)
	{
		x = manage_hash(GET, MAPSIZE);
		y = manage_hash(GET, MAPSIZE);
		mountains[x][y] = 1;

		draw_disk(mountains, x, y, 10);

		wpt -= 1;
	}

	int o = 0;
	int p = 0;

	ptr = manage_biome_list(GET);
	while (ptr && ft_strcmp(ptr->biome, "ground"))
		ptr = ptr->next;

	t_biome_list *tmp = ptr->top;
	while (ft_strcmp(tmp->biome, "Mountain"))
		tmp = tmp->next;

	change_empty(mountains);

	// char character = mountains[o][p];
	while (o < MAPSIZE)
	{
		p = 0;
		// character = mountains[0][0];
		while (p < MAPSIZE)
		{
			// int rand_mountain = manage_hash(GET, 3) + 1;

			// if (rand_mountain == 0)
			// {
			// 	if (o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
			// 		&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1])
			// 	map[o][p] = tmp->id;
			// }
			// else if (rand_mountain == 1)
			// {
			// 	if (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
			// 		&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
			// 	map[o][p] = tmp->id;
			// }
			// else if (rand_mountain == 2)
			// {
			// 	if (o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
			// 		&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
			// 	map[o][p] = tmp->id;
			// }
			// else
			// {
			// 	if (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
			// 		&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1])
			// 	map[o][p] = tmp->id;
			// }


			if ((o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
							&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1])
				|| (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
				&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
				|| (o + 1 < MAPSIZE && mountains[o][p] != mountains[o + 1][p]
					&& p - 1 >= 0 && mountains[o][p] != mountains[o][p - 1])
				|| (o - 1 >= 0 && mountains[o][p] != mountains[o - 1][p]
					&& p + 1 < MAPSIZE && mountains[o][p] != mountains[o][p + 1]))
			{
				// character = mountains[o][p];
				map[o][p] = tmp->id;
			}
			p += 1;
		}
		o += 1;
	}

	print_array(mountains);


	ptr = manage_biome_list(GET);
	while (ptr && ft_strcmp(ptr->biome, "ground"))
		ptr = ptr->next;


	tmp = ptr->top;
	while (tmp->data != FILL)
		tmp = tmp->next;

	int a = 0;
	int b = 0;
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

	map[MAPSIZE / 2][MAPSIZE / 2] = 1;

	return (map);
}

void		print_map(char **map)
{
	int		i;
	int		j;

	if (!map)
	{
		ft_printf("no map\n");
		return ;
	}
	i = 0;
	while (i < MAPSIZE)
	{
		j = 0;
		while (j < MAPSIZE)
		{
			if (map[i][j] == -1)
				ft_printf(" \e[38;5;8mE\e[0m ");
			else if (map[i][j] == 0)
				ft_printf(" \e[38;5;0mcitadelle\e[0m ");
			else if (map[i][j] == 1)
				ft_printf(" \e[38;5;1mW\e[0m ");
			else if (map[i][j] == 2)
				ft_printf(" \e[38;5;15mF\e[0m ");
			else if (map[i][j] == 3)
				ft_printf(" \e[38;5;0mground\e[0m ");
			else if (map[i][j] == 4)
				ft_printf(" \e[38;5;112mP\e[0m ");
			else if (map[i][j] == 5)
				ft_printf(" \e[38;5;22mF\e[0m ");
			else if (map[i][j] == 6)
				ft_printf(" \e[38;5;22mF\e[0m ");
			else if (map[i][j] == 7)
				ft_printf(" \e[38;5;94mH\e[0m ");
			else if (map[i][j] == 8)
				ft_printf(" \e[38;5;252mM\e[0m ");
			else if (map[i][j] == 9)
				ft_printf(" \e[38;5;0mwater\e[0m ");
			else if (map[i][j] == 10)
				ft_printf(" \e[38;5;44mL\e[0m ");
			else if (map[i][j] == 11)
				ft_printf(" \e[38;5;25mR\e[0m ");

			j += 1;
		}
		ft_printf("\n");
		i += 1;
		}
	}

	char		**manage_map(int macro, int hash)
	{
		static char		**map;

	if (macro == GET)
		return (map);
	else if (macro == NEW)
		map = new_map(hash);
	else if (macro == PRINT)
		print_map(map);
	else
		ft_printf("useless call to manage_map\n");
	return (NULL);
}
