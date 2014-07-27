#include <RPG.h>
#include <string.h>
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
	heros->experience += 1;
}

void			game_run()
{
	// int				key;
	WINDOW			*win;
	WINDOW			*menu;
	t_heros			*heros;
	t_heros_list	*head;
	int				i;
	int				cmp;

	cbreak();
	noecho();
	// halfdelay(8);
	// key = -1;
	// int fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	i = 0;
	while (42)
	{
		// write(fd, "test\n", 5);
		manage_win_list(DELETE, NULL); // DELETE MAIN SCREEN
		menu = manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
		// if (key == -1)
		i += 1;
		head = manage_heros_list(GET, NULL);
		cmp = 5;
		mvwprintw(win, cmp - 2, 5, "%5s %10s %10s %10s %5s/%s", "id", "name", "level", "location", "xp", "xp to lvl"); // PRINT EVERY HEROS
		while (head)
		{
			heros = head->heros;
			tick_heros(menu, head->heros); // PLAY EVERY HEROS
			mvwprintw(win, cmp, 5, "%5d %10s, %10d at %-10s | %d/%d", heros->id, heros->name, heros->level, heros->location, heros->experience, heros->level * 10); // PRINT EVERY HEROS
			head = head->next;
			cmp += 1;
		}
		wrefresh(win); // WRITE TEXT ON SCREEN
		usleep(100 * 8000);

		// key = wgetch(win);
		// DO KEY
		// key = -1;
	}
	// close(fd);
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

