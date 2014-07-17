/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_curse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:19 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 11:27:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINDOW	*manage_ncurses(int macro)
{
	static WINDOW	*main_win;

	if (macro == GET)
		return (main_win);
	else if (macro == NEW)
	{
		if (!(main_win = initscr()))
		{
			int fd;
			fd = open("debug", O_CREAT | O_TRUNC | O_WRONLY, 0755);
			write(fd, "Error initialising ncurses.\n", 28);
			close(fd);
			exit(0);
		}
		cbreak();
		noecho();
		curs_set(0);
	}
	else
		ft_printf("Useless call to manage_ncurses\n");
	return (NULL);
}
