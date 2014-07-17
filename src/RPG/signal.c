/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 04:08:29 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 05:32:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

static void			resize(int sig)
{
	(void)sig;
	resizeterm(20, 20);

	t_win_list		*head;

	head = manage_win_list(GET, NULL);
	while (head)
	{
		// destroy_win(head->win);
		mvwprintw(head->win, 1, 1, "%d \\ %d\n", LINES, COLS);
		refresh_win(head->win);
		head = head->next;
	}
	// manage_ncurses(SET);
	// manage_win(NEW, create_wintab(LINES, COLS / 4, 0, COLS - COLS / 4));
	// manage_win(NEW, create_wintab(LINES, COLS - COLS / 4, 0, 0));
}

void				ft_signal(void)
{
	void			(*array[1])(int) = {resize};

	signal(SIGWINCH, array[SIG_WINCH]);
}
