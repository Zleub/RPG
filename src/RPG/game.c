/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 10:03:57 by Arno              #+#    #+#             */
/*   Updated: 2014/07/20 22:43:19 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	static int		cmp;

	new = create_heros();
	hash = ft_hash(str);
	new->name = str;
	new->location = "Citadel";
	new->experience = 0;
	new->level = 0;
	new->armor = 0;
	new->strengh = hash % 21;
	new->life = 20;
	new->id = cmp;
	manage_heros_list(ADD, new);
	cmp += 1;
	return (new);
}

void			get_name(WINDOW *win)
{
	char	str[80];
	int		validate;
	t_heros	*heros;

	validate = 0;
	while (validate == 0)
	{
		ft_bzero(str, 80);
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

#include <time.h>

void		tick_heros(WINDOW *menu, t_heros *heros) // GAME MECHANISM EXAMPLE ??
{
	static int tmp;
	static int vendredi;

	mvwprintw(menu, 1, 1, "tmp: %d", tmp);
	mvwprintw(menu, 2, 1, "vendredi: %d", vendredi);
	wrefresh(menu);

	if (heros->experience == heros->level * 10)
	{
		heros->experience = 0;
		heros->level += 1;
	}
	if (heros->level >= 5)
	{
			if (!tmp || tmp < 10)
				tmp = (int)time(NULL);
			else if ((tmp % 100) == 0)
			{
				if (!vendredi)
				{
					vendredi = 1;
					new_char("Vendredi");
				}
			}
			else
				tmp /= 10;
	}
	heros->experience += 1;
}

void			game_run()
{
	// int				key;
	WINDOW			*win;
	WINDOW			*menu;
	t_heros_list	*head;
	int				i;
	int				cmp;

	cbreak();
	noecho();
	// halfdelay(8);
	// key = -1;
	int fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	i = 0;
	while (42)
	{
		write(fd, "test\n", 5);
		manage_win_list(DELETE, NULL); // REFRESH MAIN SCREEN
		menu = manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
		// if (key == -1)
		i += 1;
		head = manage_heros_list(GET, NULL);
		cmp = 5;
		mvwprintw(win, cmp - 2, 5, "%5s %10s %10s %10s %5s/%s", "id", "name", "level", "location", "xp", "xp to lvl"); // PRINT EVERY HEROS
		while (head)
		{
			tick_heros(menu, head->heros); // PLAY EVERY HEROS
			mvwprintw(win, cmp, 5, "%5d %10s, %10d at %-10s | %d/%d", head->heros->id, head->heros->name, head->heros->level, head->heros->location, head->heros->experience, head->heros->level * 10); // PRINT EVERY HEROS
			head = head->next;
			cmp += 1;
		}
		wrefresh(win);
		usleep(100 * 8000);
		// key = wgetch(win);
		// DO KEY
		// key = -1;
	}
	close(fd);
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

