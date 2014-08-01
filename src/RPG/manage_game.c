#include <RPG.h>
#include <string.h>
#include <time.h>

void		event_vendredi(t_heros *heros)
{
	static int tmp;

	if (heros->level >= 5)
	{
		if (!tmp || tmp < 100)
			tmp = (int)time(NULL);
		else if ((tmp % 100) == 0)
			manage_char(NEW, "Vendredi");
		else
			tmp /= 10;
	}
}

void		event_calendar(t_heros *heros)
{
	heros->cmp += 1;
	if (heros->cmp == heros->state->time)
	{
		heros->state = heros->state->next;
		heros->cmp = 0;
	}
}

void		tick_heros(t_heros *heros) // GAME MECHANISM EXAMPLE ??
{
	if (manage_game(GET)->count == 1)
		event_vendredi(heros);

	event_calendar(heros);
	heros->ticks += 1;
	if (heros->ticks % 10 == 0)
		heros->experience += 1;
	if (heros->experience == heros->level * 10)
	{
		heros->experience = 0;
		heros->level += 1;
	}
	if (heros->ticks == 36 * 600) // 60 is the sum of every calendar step
	{
		heros->age += 1;
		heros->ticks = 0;
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

void			print_menu(WINDOW *menu)
{
	int			i;
	t_heros_list	*head;

	if (manage_game(GET)->select > 0)
	{
		i = manage_game(GET)->select - 1;
		head = manage_heros_list(GET, NULL);
		while (i)
		{
			head = head->next;
			i -= 1;
		}
		mvwprintw(menu, 1, 1, "%s, lvl %d", head->heros->name, head->heros->level);
		mvwprintw(menu, 2, 1, "str: %d", head->heros->strengh);
		mvwprintw(menu, 3, 1, "def: %d", head->heros->armor);
		mvwprintw(menu, 4, 1, "age: %d", head->heros->age);
		mvwprintw(menu, 5, 1, "xp: %d", head->heros->experience);
		mvwprintw(menu, 6, 1, "state: %s", head->heros->state->event);
		mvwprintw(menu, 7, 1, "job: %s", head->heros->job);
		if (DEBUG == 1)
		{
			mvwprintw(menu, 8, 1, "cmp: %d", head->heros->cmp);
			mvwprintw(menu, 9, 1, "ticks: %d", head->heros->ticks);
		}
	}
}

void			print_main(WINDOW *win)
{
	t_heros_list	*head;
	t_heros			*heros;
	int				cmp;

	cmp = 5;
	mvwprintw(win, cmp - 2, 5, "%5s %10s %10s %10s %5s/%s", "id", "name", "level", "activity", "xp", "xp to lvl"); // PRINT EVERY HEROS
	head = manage_heros_list(GET, NULL);
	while (head)
	{
		heros = head->heros;
		mvwprintw(win, cmp, 5, "%5d %10s, %10d %-10s | %d/%d", heros->id, heros->name, heros->level, heros->state->event, heros->experience, heros->level * 10); // PRINT EVERY HEROS
		tick_heros(head->heros); // PLAY EVERY HEROS
		head = head->next;
		cmp += 1;
	}
}

void			game_run()
{
	WINDOW			*win;
	WINDOW			*menu;

	noecho();
	int fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	while (42)
	{
		manage_win_list(DELETE, NULL); // DELETE MAIN SCREEN

		get_key(fd);

		menu = manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
		win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
		print_main(win);
		print_menu(menu);
		wrefresh(win); // WRITE TEXT ON SCREEN
		wrefresh(menu); // WRITE TEXT ON SCREEN
		usleep(100 * 800);
	}
	close(fd);
}

t_gameplay		*manage_game(int macro)
{
	static t_gameplay	*game;

	if (macro == GET)
		return (game);
	else if (macro == NEW)
		game = game_new(game);
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
			exit (0);
	}
	else
		ft_printf("Useless call to manage_game\n");
	return (NULL);
}
