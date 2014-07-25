/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPG.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/07/25 02:59:25 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPG_H
# define RPG_H

#include <libft.h>
#include <fcntl.h>
#include <signal.h>
#include <curse.h>

#include <stdio.h>


#define STRING char*

typedef struct		s_heros
{
	STRING			name;
	STRING			location;
	int				level;
	int				experience;
	int				strengh;
	int				armor;
	int				life;
	int				id;
}					t_heros;

typedef struct			s_heros_list
{
	t_heros				*heros;
	struct s_heros_list	*next;
}						t_heros_list;

typedef struct	s_gameplay
{
	int			status;
}				t_gameplay;

enum				e_content
{
	NAME, LOCATION, LEVEL, EXPERIENCE, STRENGH, ARMOR, LIFE
};

enum				e_gameplay
{
	MENU, RUN
};

enum				e_signal
{
	SIG_WINCH, SIG_TSTP, SIG_CONT, SIG_INT
};

/*
** manage_char.c
*/
t_heros				*new_char(STRING str);


/*
** game_menu.c
*/
void				game_menu(t_gameplay *game);

/*
** game.c
*/
t_gameplay			*manage_game(int macro);

/*
** new_game.c
*/
t_gameplay			*new_game(t_gameplay *game);
void				ft_signal(void);

/*
** manage_char_list.c
*/
t_heros_list	*manage_heros_list(int macro, t_heros *heros);

#endif
