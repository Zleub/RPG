/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:19 by adebray           #+#    #+#             */
/*   Updated: 2014/07/15 19:39:51 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINDOW	*manage_ncurses(int macro)
{
	static WINDOW	*main_win;

	if (macro == GET)
		return (main_win);
	else if (macro == SET)
	{
		if ((main_win = initscr()) == NULL)
		{
			ft_printf("Error initialising ncurses.\n");
			exit(0);
		}
	}
	else if (macro == NEW)
	{
		;
	}
	else
		ft_printf("Useless call to manage_ncurses\n");
	return (NULL);
}
