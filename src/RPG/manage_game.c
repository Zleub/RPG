#include <RPG.h>
#include <string.h>
#include <time.h>

void		tick_heros(t_heros *heros) // GAME MECHANISM EXAMPLE ??
{
	static int tmp;
	static int vendredi;
	static int cmp;

	if (heros->experience == heros->level * 10)
	{
		heros->experience = 0;
		heros->level += 1;
	}
	if (heros->level >= 5)
	{
		if (!tmp || tmp < 100)
			tmp = (int)time(NULL);
		else if ((tmp % 100) == 0)
		{
			if (!vendredi)
			{
				vendredi = 1;
				manage_char(NEW, "Vendredi");
			}
		}
		else
			tmp /= 10;
	}
	cmp += 1;
	if (cmp == 10)
	{
		heros->experience += 1;
		cmp = 0;
	}
}

void			get_key(int fd)
{
	int				key;

	timeout(0);
	key = getch();
	if (key != -1)
	{
		ft_putnbr_fd(key, fd);
		ft_putendl_fd("", fd);
		if (key == 32)
		{
			manage_game(GET)->select += 1;
			if (manage_game(GET)->select > manage_game(GET)->count)
				manage_game(GET)->select = 0;
			dprintf(fd, "test : %d\n", manage_game(GET)->select);
		}
		while ((key = getch()) != EOF && key != '\n')
		{
			;
		}
		key = -1;
	}
}

void			game_run()
{
	WINDOW			*win;
	WINDOW			*menu;
	t_heros			*heros;
	t_heros_list	*head;
	int				i;
	int				cmp;

	// cbreak();
	noecho();
	// key = -1;
	i = 0;
	int fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	while (42)
	{
		manage_win_list(DELETE, NULL); // DELETE MAIN SCREEN

		get_key(fd);

		menu = manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
		// if (key == -1)
		i += 1;
		cmp = 5;
		mvwprintw(win, cmp - 2, 5, "%5s %10s %10s %10s %5s/%s", "id", "name", "level", "location", "xp", "xp to lvl"); // PRINT EVERY HEROS
		if (manage_game(GET)->select > 0)
		{
			int i = manage_game(GET)->select - 1;
			head = manage_heros_list(GET, NULL);
			while (i)
			{
				head = head->next;
				i -= 1;
			}
			mvwprintw(menu, 1, 1, "name: %s", head->heros->name);
			mvwprintw(menu, 2, 1, "str: %d", head->heros->strengh);
			mvwprintw(menu, 3, 1, "def: %d", head->heros->armor);
		}

		head = manage_heros_list(GET, NULL);
		while (head)
		{
			heros = head->heros;
			mvwprintw(win, cmp, 5, "%5d %10s, %10d at %-10s | %d/%d", heros->id, heros->name, heros->level, heros->location, heros->experience, heros->level * 10); // PRINT EVERY HEROS
			tick_heros(head->heros); // PLAY EVERY HEROS
			head = head->next;
			cmp += 1;
		}
		wrefresh(win); // WRITE TEXT ON SCREEN
		wrefresh(menu); // WRITE TEXT ON SCREEN
		usleep(100 * 800);


		// DO KEY
		// key = -1;
	}
	close(fd);
}

t_gameplay		*manage_game(int macro)
{
	static t_gameplay	*game;

	if (macro == GET)
		return (game);
	else if (macro == NEW)
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
