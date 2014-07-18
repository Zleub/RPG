#include <RPG.h>
#include <string.h>

int			cols_center(char *str)
{
	return ((COLS - ft_strlen(str)) / 2);
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

void			game_menu(t_gameplay *game)
{
	WINDOW	*win;
	char	str[80];
	int		validate;

	win = manage_win(NEW, create_wintab(LINES, COLS, 0, 0));
	mvwprintw(win, lines_center() - 1, cols_center("Hi. What's your name ?"), "Hi. What's your name ?");
	wmove(win, lines_center(), cols_center("12345"));

	validate = 0;
	ft_bzero(str, 80);
	while (validate == 0)
	{
		wscanw(win, "%s", &str);
		if (ft_isalpha(str[0]))
			validate = 1;
		else
		{
			wmove(win, lines_center(), cols_center("12345"));
			ft_bzero(str, 80);
		}
	}
	game->status = RUN;
	manage_game(PRINT);
}

void			game_run()
{
	int		key;
	WINDOW	*win;

	cbreak();
	noecho();

	manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
	win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));

	key = -1;
	while (key != 127)
	{
		key = wgetch(win);
	}
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
			game_menu(game);
		else if (game->status == RUN)
			game_run();
		else
		{
			;
		}
	}
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}

