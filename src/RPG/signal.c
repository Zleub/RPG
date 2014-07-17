/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 04:08:29 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 18:20:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

void			resize(int sig)
{
	struct winsize w;

	(void)sig;

	manage_win_list(DELETE, NULL);
	manage_wintab_list(DELETE, NULL);

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	resizeterm(w.ws_row, w.ws_col);

	manage_game(PRINT);

	manage_win_list(PRINT, NULL);
	manage_wintab_list(PRINT, NULL);

}

void				ft_signal(void)
{
	void			(*array[1])(int) = {resize};

	signal(SIGWINCH, array[SIG_WINCH]);
}
