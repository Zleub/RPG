/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wintab_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:44:53 by adebray           #+#    #+#             */
/*   Updated: 2014/07/16 04:46:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINTAB		manage_wintab_list(int macro, WINTAB array)
{
	static WINTABLIST	head;

	if (macro == GET)
		return (head->array);
	else if (macro == SET)
	{
		if (!head)
			head->array = array;
		else
			ft_printf("Head already set\n");
	}
	// else if (macro == ADD)
		// add_wintab_list(head, array);
	else
		ft_printf("Useless call to manage_win\n");
	return (NULL);
}
