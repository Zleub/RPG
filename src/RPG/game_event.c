/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 21:12:19 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:13:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <time.h>

void		event_vendredi(t_heros *heros)
{
	static int tmp;

	if (heros->level >= 5)
	{
		if (!tmp || tmp < 100)
			tmp = (int)time(NULL);
		else if ((tmp % 100) == 0)
			manage_char(NEW, "Vendredi");
		else
			tmp /= 10;
	}
}

void		event_calendar(t_heros *heros)
{
	heros->cmp += 1;
	if (heros->cmp == heros->state->time)
	{
		heros->state = heros->state->next;
		heros->cmp = 0;
	}
}
