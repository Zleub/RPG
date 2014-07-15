/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:47 by adebray           #+#    #+#             */
/*   Updated: 2014/07/15 19:39:52 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINDOW	*manage_win(int macro, WINTAB array)
{
	static WINDOW	*ptr;

	if (macro == GET)
		return (ptr);
	else if (macro == SET)
		ptr = object;
	else if (macro == NEW)
		ptr = create_newwin(height, width, starty, startx);
	else
		ft_printf("Useless call to manage_win\n");
	return (NULL);
}
