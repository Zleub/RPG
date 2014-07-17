#include <RPG.h>

int			cols_center(char *str)
{
	return (COLS / 2 - ft_strlen(str) / 2);
}

int			lines_center()
{
	return (LINES / 2);
}

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
		game->status = MENU;
		ft_signal();
		manage_ncurses(NEW);
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
		game = new_game(game);
	else if (macro == DELETE)
	{
		endwin();
		delwin(manage_ncurses(GET));
	}
	else if (macro == PRINT)
	{
		if (game->status == MENU)
		{
			WINDOW	*win;

			win = manage_win(NEW, create_wintab(LINES, COLS, 0, 0));
			mvwprintw(win, lines_center() - 1, cols_center("Hi. What's your name ?"), "Hi. What's your name ?");
			refresh_win(win);
		}
		else if (game->status == RUN)
		{
			manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
			manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
		}
		else
		{
			;
		}
	}
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}

