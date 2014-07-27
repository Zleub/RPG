/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/25 02:54:22 by adebray           #+#    #+#             */
/*   Updated: 2014/07/27 11:33:01 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

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
			// if (!manage_heros_list(LOAD, heros))
			// {
				// manage_ char(SET, heros);
				heros = new_char(ft_strdup(str));
				// manage_heros_list(ADD, heros);
				// CREATE A NEW GAME
			// }
			// else
			// {
				// CHAR_LIST IS UP TO DATE
				// ;
				// return
			// }
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
