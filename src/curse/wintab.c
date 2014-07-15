/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wintab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 19:39:32 by adebray           #+#    #+#             */
/*   Updated: 2014/07/15 19:55:47 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

WINTAB		create_wintab(int i, int j, int x, int y)
{
	WINTAB	array;

	if (!(array = (WINTAB)malloc(sizeof(int) * 4)))
		return (NULL);
	array[0] = i;
	array[1] = j;
	array[2] = x;
	array[3] = y;
	manage_wintab_list(ADD, array);
	return (array);
}

WINTAB		manage_wintab_list(int macro, WINTAB array)
{
	static WINTABLIST	head;

	if (macro == GET)
		return (head);
	else if (macro == SET)
		head = object;
	else if (macro == NEW)
		head = create_wintab(0, 0, 0, 0);
	else if (macro == ADD)
		add_wintab_list(head, array);
	else
		ft_printf("Useless call to manage_win\n");
}
