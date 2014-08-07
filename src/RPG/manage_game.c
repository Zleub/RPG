/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 03:21:53 by adebray           #+#    #+#             */
/*   Updated: 2014/08/07 19:22:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

void		tick_heros(t_heros *heros) // GAME MECHANISM EXAMPLE ??
{
	if (manage_game(GET)->count == 1)
		event_vendredi(heros);
	else
		event_rand_char(heros);

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
		else if (key == 9)
		{
			if (manage_game(GET)->run_menu == 1)
				manage_game(GET)->run_menu = 0;
			else
				manage_game(GET)->run_menu = 1;
		}
		else if (key == 109)
		{
			if (manage_game(GET)->run_map == 1)
				manage_game(GET)->run_map = 0;
			else
				manage_game(GET)->run_map = 1;
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

	noecho();
	int fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
	while (42)
	{
		manage_win_list(DELETE, NULL); // DELETE MAIN SCREEN

		get_key(fd);

		if (manage_game(GET)->run_menu == 1)
			win = manage_win(NEW_B, create_wintab(LINES, COLS, 0, 0));
		else
		{
			win = manage_win(NEW_B, create_wintab(LINES, COLS - COLS / 4, 0, 0));
			menu = manage_win(NEW_B, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
			print_menu(menu);
			wrefresh(menu); // WRITE TEXT ON SCREEN
		}
		print_main(win);
		wrefresh(win); // WRITE TEXT ON SCREEN
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
