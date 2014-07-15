/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:33 by adebray           #+#    #+#             */
/*   Updated: 2014/07/15 20:10:14 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINDOW		*manage_win_list(int macro, WINDOW *object)
{
	static WINDOW	*head;

	if (macro == GET)
		return (head);
	else if (macro == SET)
		head = object;
	else if (macro == NEW)
	{
		;
	}
	else if (macro == ADD)
		add_win_list(head, object);
	else
		ft_printf("Useless call to manage_win_list\n");
	return (NULL);
}
