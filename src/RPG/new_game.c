/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/25 02:49:04 by adebray           #+#    #+#             */
/*   Updated: 2014/07/25 02:51:23 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_gameplay	*create_game(void)
{
	t_gameplay	*new;

	new = (t_gameplay*)malloc(sizeof(t_gameplay));
	new->status = -1;
	return (new);
}

t_gameplay		*new_game(t_gameplay *game)
{
	if (!game)
	{
		game = create_game();
		game->status = MENU;
		ft_signal();
		manage_ncurses(NEW);
	}
	else
	{
		free(game);
		game = NULL;
		new_game(game);
	}
	return (game);
}
