#include <RPG.h>

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

int		ft_abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (x * -1);
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

void		new_point(t_biome_list *tmp)
{
	int		x;
	int		y;

	x = manage_hash(GET, MAPSIZE);
	y = manage_hash(GET, MAPSIZE);
	manage_bpoint_list(NEW, create_wintab(x, y, tmp->id, tmp->data));
}

void		collect_wpoint()
{
	t_biome_list	*ptr;
	t_biome_list	*tmp;
	int				biome_rand;
	int				i;

	ptr = get_biome_ptr("water");
	i = count_biome_top(ptr->top);
	biome_rand = manage_hash(GET, i);

	tmp = ptr->top;
	i = biome_rand;
	while (i--)
		tmp = tmp->next;
	new_point(tmp);
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

void		collect_gpoint()
{
	t_biome_list	*ptr;
	t_biome_list	*tmp;
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
		while (tmp->data != LINE && tmp->data != CIRCLE)
			tmp = tmp->next;
		tmp = tmp->next;
		biome_rand -= 1;
	}
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
		collect_gpoint();
		wpt -= 1;
	}
}

char		**create_mountains(void)
{
	int		x;
	int		y;
	int		wpt;
	char	**mountains;

	mountains = create_map();
	wpt = manage_hash(GET, 3) + MAPSIZE / 5;
	while (wpt)
	{
		x = manage_hash(GET, MAPSIZE);
		y = manage_hash(GET, MAPSIZE);
		mountains[x][y] = 1;

		draw_disk(mountains, x, y, MAPSIZE / 3);
		wpt -= 1;
	}
	return (mountains);
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

void		draw_mountains(char **map)
{
	t_biome_list	*tmp;
	t_biome_list	*ptr;
	char			**mountains;

	mountains = create_mountains();

	ptr = get_biome_ptr("ground");

	tmp = ptr->top;
	while (ft_strcmp(tmp->biome, "Mountain"))
		tmp = tmp->next;

	change_empty(mountains);
	write_mountains(map, mountains, tmp->id);
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

char		**new_map(int hash)
{
	char	**map;

	map = create_map();

	manage_biome_list(NEW);

	manage_hash(SET, hash);
	manage_hash(PRINT, 0);

	collect_bpoint();

	draw_mountains(map);
	draw_bpoint(map);
	fill_map(map);
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
