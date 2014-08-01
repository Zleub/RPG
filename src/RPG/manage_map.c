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

char		**new_map(int hash)
{
	int		x;
	int		y;
	char	**map;
	size_t	gene_nb;

	map = create_map();

	manage_biome_list(NEW);
	manage_biome_list(PRINT);

	map[6][6] = 1;

	gene_nb = hash;
	ft_printf("-> %d\n", gene_nb);
	int wpt = (gene_nb % 3) + 1;
	ft_printf("-> %d\n", wpt);
	gene_nb = update_hash(gene_nb, 3);
	while (wpt)
	{
		ft_printf("rand type: %d\n", gene_nb % 4);
		gene_nb = update_hash(gene_nb, 10);

		x = gene_nb % 13;
		gene_nb = update_hash(gene_nb, 13);
		y = gene_nb % 13;
		gene_nb = update_hash(gene_nb, 13);
		map[x][y] = 2;
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
