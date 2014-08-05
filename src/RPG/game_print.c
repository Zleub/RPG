/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 21:14:55 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:15:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

void			print_menu(WINDOW *menu)
{
	int			i;
	t_heros_list	*head;

	if (manage_game(GET)->select > 0)
	{
		i = manage_game(GET)->select - 1;
		head = manage_heros_list(GET, NULL);
		while (i)
		{
			head = head->next;
			i -= 1;
		}
		mvwprintw(menu, 1, 1, "%s, lvl %d", head->heros->name, head->heros->level);
		mvwprintw(menu, 2, 1, "str: %d", head->heros->strengh);
		mvwprintw(menu, 3, 1, "def: %d", head->heros->armor);
		mvwprintw(menu, 4, 1, "age: %d", head->heros->age);
		mvwprintw(menu, 5, 1, "xp: %d", head->heros->experience);
		mvwprintw(menu, 6, 1, "state: %s", head->heros->state->event);
		mvwprintw(menu, 7, 1, "job: %s", head->heros->job);
		if (DEBUG == 1)
		{
			mvwprintw(menu, 8, 1, "cmp: %d", head->heros->cmp);
			mvwprintw(menu, 9, 1, "ticks: %d", head->heros->ticks);
		}
	}
}

void			print_main(WINDOW *win)
{
	t_heros_list	*head;
	t_heros			*heros;
	int				cmp;

	cmp = 5;
	mvwprintw(win, cmp - 2, 5, "%5s %10s %10s %10s %5s/%s", "id", "name", "level", "activity", "xp", "xp to lvl"); // PRINT EVERY HEROS
	head = manage_heros_list(GET, NULL);
	while (head)
	{
		heros = head->heros;
		mvwprintw(win, cmp, 5, "%5d %10s %10d %-10s | %d/%d", heros->id, heros->name, heros->level, heros->state->event, heros->experience, heros->level * 10); // PRINT EVERY HEROS
		tick_heros(head->heros); // PLAY EVERY HEROS
		head = head->next;
		cmp += 1;
	}
}
