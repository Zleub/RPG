#include <RPG.h>
#include <limits.h>

int					ft_hash(char *line)
{
	int				hash;
	int				c;

	hash = 5381;
	while ((c = *line++))
		hash = ((hash << 5) + hash) ^ c;
	if (hash < 0)
		return (hash * -1);
	else
		return (hash);
}

size_t		update_hash(size_t hash, int diviser)
{
	if (hash / diviser <= 5381)
		return (INT_MAX - hash / diviser);
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
			hash = hash / nbr ^ initial;
		else
			hash = hash / nbr;
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
