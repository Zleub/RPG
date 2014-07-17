/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 11:22:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSE_H
# define CURSE_H

# include <ncurses.h>
# include <ft_printf.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include <sys/ioctl.h>

enum	e_manage
{
	GET, SET, NEW, ADD, PRINT, FRESH, DELETE
};

typedef struct				s_win_list
{
	WINDOW					*win;
	struct s_win_list		*next;
}							t_win_list;

# define WINTAB int

typedef struct				s_wintab_list
{
	WINTAB					*array;
	struct s_wintab_list	*next;
}							t_wintab_list;

# define WINTABLIST t_wintab_list

WINDOW						*manage_ncurses(int macro);

t_win_list					*manage_win_list(int macro, WINDOW *object);

WINDOW						*manage_win(int macro, WINTAB *array);
void						print_win(WINDOW *ptr);
void						print_win_fd(WINDOW *ptr, int fd);
void						refresh_win(WINDOW *win);
void						destroy_win(WINDOW *win);

WINTABLIST					*manage_wintab_list(int macro, WINTAB *array);

WINTAB						*manage_wintab(int macro, WINTAB *array);
WINTAB						*create_wintab(int i, int j, int x, int y);
void						print_wintab_fd(WINTAB *array, int fd);
void						destroy_wintab(WINTAB *ptr);

#endif
