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

int				is_valide_name(char *name)
{
	int		validate;
	int		i;

	i = 0;
	validate = 0;
	while (name[i])
	{
		if (ft_isalpha(name[i]))
			validate = 1;
		else
			validate = 0;
		i += 1;
	}
	if (validate)
		return (1);
	else
		return (0);
}

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

t_heros				*new_char(STRING str)
{
	t_heros			*new;
	int				hash;

	new = create_heros();
	hash = ft_hash(str);
	new->name = str;
	new->location = "Taverne";
	new->experience = 0;
	new->level = 0;
	new->armor = 0;
	new->strengh = hash % 21;
	new->life = 20;
	manage_heros_list(ADD, new);
	return (new);
}

void			get_name(WINDOW *win)
{
	char	str[80];
	int		validate;
	t_heros	*heros;

	validate = 0;
	ft_bzero(str, 80);
	while (validate == 0)
	{
		wscanw(win, "%s", &str);
		if (is_valide_name(str))
		{
			heros = new_char(str);
			heros->name = ft_strdup(str);
			if (!manage_heros_list(LOAD, heros))
			{
				// manage_ char(SET, heros);
				manage_heros_list(ADD, heros);
				// CREATE A NEW GAME
			}
			else
			{
				// CHAR_LIST IS UP TO DATE
				;
				// return
			}
			validate = 1;
		}
		else
		{
			mvwprintw(win, lines_center(), cols_center("12345"), "%80c", ' ');
			wmove(win, lines_center(), cols_center("12345"));
			ft_bzero(str, 80);
		}
	}
}

void			game_menu(t_gameplay *game)
{
	WINDOW	*win;

	win = manage_win(NEW, create_wintab(LINES, COLS, 0, 0));
	mvwprintw(win, lines_center() - 1, cols_center("Hi. What's your name ?"), "Hi. What's your name ?");
	wmove(win, lines_center(), cols_center("12345"));
	get_name(win);
	game->status = RUN;
	manage_game(PRINT);
}

void			game_run()
{
	int				key;
	WINDOW			*win;
	t_heros_list	*head;
	static int		i;

	cbreak();
	noecho();
	manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
	win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
	halfdelay(8);
	key = -1;
	while (key != 127)
	{
		if (key == -1)
			i += 1;
		head = manage_heros_list(GET, NULL);
		while (head)
		{
			mvwprintw(win, 5, 5, "%d %s, lvl: %d at %s", i, head->heros->name, head->heros->level, head->heros->location);
			head = head->next;
		}
		key = wgetch(win);
		manage_win_list(DELETE, NULL);
		manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
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
		ft_printf("Useless call to manage_game\n");
	return (NULL);
}

