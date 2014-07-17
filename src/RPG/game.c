#include <RPG.h>
#include <curse.h>

/* void        taverne(t_heros *character)
{
	char    *str;

	ft_printf("You are in the tavern.\n");
	ft_printf("(S)leep.\n");
	ft_printf("Go (H)unt.\n");
	ft_printf("(S)hop.\n");
	if (!(get_next_line(1, &str)))
		return (0);
	else if (str[0] == 'S')
		sleep()
	else if (str[0] == 'H')
}

void        game(t_heros *character)
{
	if (!ft_strcmp(character->location, "Taverne"))
		taverne(character);
} */

t_gameplay	*create_game(void)
{
	t_gameplay	*new;

	new = (t_gameplay*)malloc(sizeof(t_gameplay));
	new->status = -1;
	return (new);
}

t_gameplay		*new_game(t_gameplay *game)
{
	if (!game)
	{
		game = create_game();
		ft_signal();
		manage_ncurses(NEW);
		manage_win(NEW, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		manage_win(NEW, create_wintab(LINES, COLS - COLS / 4, 0, 0));
	}
	else
	{
		free(game);
		game = NULL;
		new_game(game);
	}
	return (game);
}

t_gameplay		*manage_game(int macro)
{
	static t_gameplay	*game;

	if (macro == NEW)
		new_game(game);
	else if (macro == DELETE)
	{
		endwin();
		delwin(manage_ncurses(GET));
	}
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}

