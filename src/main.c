/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/08/08 21:47:22 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

t_biome_conf		*manage_biome_conf(int macro);

int					main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	manage_game(NEW);
	manage_game(PRINT);

	endwin();
	delwin(manage_ncurses(GET));


	// manage_map(NEW, ft_hash(argv[1]));
	// manage_map(PRINT, 0);
	return (0);
}
