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
		int fd;
		// char *str;

			char	str[80];
			WINDOW	*win;
		fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
		if (game->status == MENU)
		{

			win = manage_win(NEW, create_wintab(LINES, COLS, 0, 0));
			mvwprintw(win, lines_center() - 1, cols_center("Hi. What's your name ?"), "Hi. What's your name ?");
			wmove(win, lines_center(), cols_center("12345"));
			int validate = 0;
			while (validate == 0)
			{
				wscanw(win, "%s", &str);
				if (ft_isalpha(str[0]))
					validate = 1;
			}
			game->status = RUN;
			manage_game(PRINT);
		}
		else if (game->status == RUN)
		{
			write(fd, "test\n", 5);
			manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
			win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
			wmove(win, lines_center(), cols_center("12345"));
			wscanw(win, "%s", &str);
		}
		else
		{
			;
		}
		close(fd);
	}
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}

