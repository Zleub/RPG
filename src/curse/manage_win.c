/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:47 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 04:41:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

WINDOW		*create_win(WINTAB array)
{
	WINDOW	*new;

	new = newwin(array[0], array[1], array[2], array[3]);
	manage_win_list(ADD, new);
	box(new, 0 , 0);
	wrefresh(new);
	return (new);
}

void		print_win(WINDOW *ptr)
{
	ft_printf("print_win\n");
	ft_printf("ptr: %p", ptr);
}

void		print_win_fd(WINDOW *ptr, int fd)
{
	char	*content;
	asprintf(&content, "print_win_fd:\n%p\n", ptr);
	write(fd, content, ft_strlen(content));
}

void		refresh_win(WINDOW *win)
{
	wrefresh(win);
}

void		destroy_win(WINDOW *win)
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

WINDOW		*manage_win(int macro, WINTAB array)
{
	static WINDOW	*ptr;

	if (macro == GET)
		return (ptr);
	// else if (macro == SET)
	// 	ptr = object;
	else if (macro == NEW)
	{
		ptr = create_win(array);
		return (ptr);
	}
	else if (macro == PRINT)
		print_win(ptr);
	else if (macro == FRESH)
		refresh_win(ptr);
	else if (macro == DELETE)
		destroy_win(ptr);
	else
		ft_printf("Useless call to manage_win\n");
	return (NULL);
}
