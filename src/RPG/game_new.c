/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/25 02:49:04 by adebray           #+#    #+#             */
/*   Updated: 2014/07/31 23:41:52 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_gameplay	*create_game(void)
{
	t_gameplay	*new;

	new = (t_gameplay*)malloc(sizeof(t_gameplay));
	new->status = -1;
	new->select = -1;
	new->count = -1;
	return (new);
}

t_gameplay		*game_new(t_gameplay *game)
{
	if (!game)
	{
		game = create_game();
		game->status = MENU;
		game->count = 0;
		game->select = 0;
		ft_signal();
		manage_ncurses(NEW);
		manage_calendar(NEW);
	}
	else
	{
		free(game);
		game = NULL;
		game_new(game);
	}
	return (game);
}
