/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 04:43:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

t_biome_conf		*manage_biome_conf(int macro);

int					main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// manage_game(NEW);
	// manage_game(PRINT);

	// endwin();
	// delwin(manage_ncurses(GET));

	manage_job_list(NEW);
	manage_job_list(PRINT);
	return (0);
}
