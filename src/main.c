/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/07/20 11:50:25 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

int					main(void)
{
	manage_game(NEW);
	manage_game(PRINT);
	endwin();
	delwin(manage_ncurses(GET));
	return (0);
}
