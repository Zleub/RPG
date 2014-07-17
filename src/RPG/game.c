#include <RPG.h>

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
		// manage_win(NEW, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		// manage_win(NEW, create_wintab(LINES, COLS - COLS / 4, 0, 0));
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
	else if (macro == print)
	{

	}
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}

