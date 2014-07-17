/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 04:08:29 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 11:27:44 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

static void			resize(int sig)
{
	struct winsize w;

	(void)sig;

	endwin();
	manage_win_list(DELETE, NULL);
	manage_wintab_list(DELETE, NULL);

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	resizeterm(w.ws_row, w.ws_col);

	manage_game(NEW);

	manage_win_list(PRINT, NULL);
	manage_wintab_list(PRINT, NULL);

}

void				ft_signal(void)
{
	void			(*array[1])(int) = {resize};

	signal(SIGWINCH, array[SIG_WINCH]);
}
