/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wintab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 19:39:32 by adebray           #+#    #+#             */
/*   Updated: 2014/07/16 06:29:36 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINTAB		create_wintab(int i, int j, int x, int y)
{
	WINTAB	array;

	if (!(array = (WINTAB)malloc(sizeof(int) * 4)))
		return (NULL);
	array[0] = i;
	array[1] = j;
	array[2] = x;
	array[3] = y;
	// manage_wintab_list(ADD, array);
	return (array);
}

