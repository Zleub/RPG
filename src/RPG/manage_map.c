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
			map[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (map);
}

size_t		update_hash(size_t hash, int diviser)
{
	if (hash / diviser == 0)
	{
		return ((unsigned)(hash / diviser - 1));
	}
	else
		return (hash / diviser);
}

void		draw_circle(char **map, int x, int y, int nbr)
{
	int q = nbr % 3 + 1;
	nbr = update_hash(nbr, 3);
	ft_printf("q: %d\n", q);
	ft_printf("draw_circle: x %d, y %d\n", x, y);
	(void)x;
	(void)y;
	int test = map[x][y];
	// while (q)
	// {
	// 	if (x + q < MAPSIZE)
	// 		map[x + q][y] = map[x][y];
	// 	if (x - q >= 0)
	// 		map[x - q][y] = map[x][y];
	// 	if (y + q < MAPSIZE)
	// 		map[x][y + q] = map[x][y];
	// 	if (y - q >= 0)
	// 		map[x][y - q] = map[x][y];
	// 	q -= 1;
	// 	if (x + q < MAPSIZE && y + q < MAPSIZE)
	// 		map[x + q][y + q] = map[x][y];
	// 	if (x - q >= 0 && y + q < MAPSIZE)
	// 		map[x - q][y + q] = map[x][y];
	// 	if (x - q >= 0 && y - q >= 0)
	// 		map[x - q][y - q] = map[x][y];
	// 	if (x + q < MAPSIZE && y - q >= 0)
	// 		map[x + q][y - q] = map[x][y];


	// for(int j=-q; j<=q; j++)
	// {
	// 	for(int i=-q; i<=q; i++)
	// 	{
	// 		if(i*i+j*j <= q * q + q * 0.8f
	// 			&& i + x >= 0 && i + x < MAPSIZE
	// 			&& j + y >= 0 && j + y < MAPSIZE)
	// 			 // && !map[j + x][i + y])
	// 		{
	// 			ft_printf("test: draw x: %d, y: %d\n", i + 5, j + 5);
	// 			map[j + 5][i + 5] = test;
	// 		}
	// 	}
	// }

	int r2 = q * q;
	int area = r2 << 2;
	int rr = q << 1;
	
	for (int i = 0; i < area; i++)
	{
	    int tx = (i % rr) - q;
	    int ty = (i / rr) - q;
	
	    if (tx * tx + ty * ty <= r2)
	    {
 			ft_printf("test: draw x: %d, y: %d\n", 5 + tx, 5 + ty);

	    	map[5 + tx][5 + ty] = test;
	    }
	        // SetPixel(x + tx, y + ty, c);
	}
}

char		**new_map(int hash)
{
	int		x;
	int		y;
	char	**map;
	size_t	nbr;

	map = create_map();

	manage_biome_list(NEW);

	map[6][6] = 1;

	nbr = hash;
	ft_printf("nbr-> %d\n", nbr);
	int wpt = (nbr % 3) + 1;
	ft_printf("wpt-> %d\n", wpt);
	nbr = update_hash(nbr, 3);
	wpt = 1;
	while (wpt)
	{
		t_biome_list *ptr = manage_biome_list(GET);
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

		int biome_rand = nbr % i;
		nbr = update_hash(nbr, i);

		tmp = ptr->top;
		i = biome_rand;
		while (i--)
			tmp = tmp->next;

		x = nbr % MAPSIZE;
		nbr = update_hash(nbr, MAPSIZE);
		y = nbr % MAPSIZE;
		nbr = update_hash(nbr, MAPSIZE);
		map[x][y] = tmp->id;

		ft_printf("%s\n", tmp->biome);

		if (tmp->data == CIRCLE)
			draw_circle(map, x, y, nbr);
		wpt -= 1;
	}



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
			if (map[i][j] == 0)
				ft_printf(" \e[90mempty\e[0m ");
			else if (map[i][j] == 1)
				ft_printf(" \e[37mCitad\e[0m ");
			else if (map[i][j] == 2)
				ft_printf(" \e[34mwater\e[0m ");
			else if (map[i][j] == 9)
				ft_printf(" \e[34m Lac \e[0m ");
			else if (map[i][j] == 10)
				ft_printf(" \e[34mRiver\e[0m ");

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
