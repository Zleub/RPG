/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/08/01 15:28:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <curse.h>

int					ft_hash(char *line);


int					main(void)
{
	// manage_game(NEW);
	// manage_game(PRINT);

	// endwin();
	// delwin(manage_ncurses(GET));
	ft_printf("%d\n", ft_hash("Arnaud"));
	manage_map(NEW, ft_hash("Arnaud"));
	manage_map(PRINT, 0);

	return (0);
}
