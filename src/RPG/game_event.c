/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 21:12:19 by adebray           #+#    #+#             */
/*   Updated: 2014/08/08 14:03:59 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>
#include <time.h>

void		event_vendredi(t_heros *heros)
{
	static int tmp;

	if (heros->level >= 5)
	{
		dprintf(2, "Vendredi: %d %% 100 : %d\n", tmp, tmp % 100);
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

void		event_rand_char(t_heros *heros)
{
	static int	check;
	int		tmp;

	tmp = 0;
	if (heros->level >= 10 && !ft_strcmp(heros->state->event, "spare"))
	{
		tmp = (int)time(NULL);
		dprintf(2, "Rand_char(%d): %d %% 100 : %d\n", check, tmp, tmp % 100);
		if ((tmp % 100) == 0 && check == 0)
		{
			dprintf(2, "Rand_char\n");
			manage_char(NEW, ft_itoa(tmp));
			check = 1;
		}
		else if ((tmp % 100) == 25 && check == 1)
		{
			dprintf(2, "Check == 0\n");
			check = 0;
		}
		else
			tmp /= 10;

	}
}
