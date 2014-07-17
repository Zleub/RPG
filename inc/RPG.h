/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPG.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/07/17 18:20:22 by adebray          ###   ########.fr       */
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
}					t_heros;

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

t_heros				*create_heros(void);
void				print_heros(t_heros *character);
void				save_heros(t_heros *character);
t_heros				*load_heros(STRING name);

t_gameplay			*manage_game(int macro);

void	ft_signal(void);
void			resize(int sig);
#endif
