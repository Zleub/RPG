/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/07/16 06:07:34 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSE_H
# define CURSE_H

# include <ncurses.h>
# include <ft_printf.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

enum	e_manage
{
	GET, SET, NEW, ADD, PRINT
};

typedef struct				s_win_list
{
	WINDOW					*win;
	struct s_win_list		*next;
}							t_win_list;

# define WINTAB int*

typedef struct				s_wintab_list
{
	WINTAB					array;
	struct s_wintab_list	*next;
}							t_wintab_list;

# define WINTABLIST t_wintab_list*

WINDOW						*manage_ncurses(int macro);
t_win_list					*manage_win_list(int macro, WINDOW *object);
void						print_win(WINDOW *ptr);
void						print_win_fd(WINDOW *ptr, int fd);
WINDOW						*manage_win(int macro, WINTAB array);
WINTAB						create_wintab(int i, int j, int x, int y);

#endif
