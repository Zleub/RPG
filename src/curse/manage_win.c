/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:55:47 by adebray           #+#    #+#             */
/*   Updated: 2014/07/16 06:20:33 by adebray          ###   ########.fr       */
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

WINDOW		*manage_win(int macro, WINTAB array)
{
	static WINDOW	*ptr;

	if (macro == GET)
		return (ptr);
	// else if (macro == SET)
	// 	ptr = object;
	else if (macro == NEW)
		ptr = create_win(array);
	else if (macro == PRINT)
		print_win(ptr);
	else
		ft_printf("Useless call to manage_win\n");
	return (NULL);
}
