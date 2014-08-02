/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/08/02 04:52:52 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

int					ft_hash(char *line);


int					main(int argc, char **argv)
{
	// manage_game(NEW);
	// manage_game(PRINT);

	// endwin();
	// delwin(manage_ncurses(GET));

	if (argc == 2)
	{
		manage_map(NEW, ft_hash(argv[1]));
		manage_map(PRINT, 0);
	}
	return (0);
}
