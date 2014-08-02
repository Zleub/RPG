/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPG.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/08/02 04:31:39 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPG_H
# define RPG_H

#include <libft.h>
#include <fcntl.h>
#include <signal.h>
#include <curse.h>

#include <stdio.h>

#define DEBUG 1
#define MAPSIZE 13
#define STRING char*

typedef struct				s_calendar_list
{
	char					*event;
	int						time;
	struct s_calendar_list	*next;
}							t_calendar_list;

typedef struct				s_biome_list
{
	char					*biome;
	int						data;
	struct s_biome_list		*next;
	struct s_biome_list		*top;
	int						id;
}							t_biome_list;

typedef struct			s_heros
{
	char				*name;
	char				*location;
	int					level;
	int					experience;
	int					strengh;
	int					armor;
	int					life;
	int					id;
	int					cmp;
	int					ticks;
	int					age;
	char				*job;
	t_calendar_list		*state;
}						t_heros;

typedef struct			s_heros_list
{
	t_heros				*heros;
	struct s_heros_list	*next;
}						t_heros_list;

typedef struct			s_gameplay
{
	int					status;
	int					count;
	int					select;
}						t_gameplay;

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

enum				e_biome_enum
{
	EMPTY, UNIQUE, FILL, CIRCLE, RECT, LINE
};

/*
** manage_char.c
*/
t_heros				*new_char(STRING str);
t_heros		*manage_char(int macro, STRING name);

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
t_gameplay			*game_new(t_gameplay *game);
void				ft_signal(void);

/*
** manage_char_list.c
*/
t_heros_list	*manage_heros_list(int macro, t_heros *heros);

/*
** manage_calendar.c
*/
t_calendar_list	*manage_calendar(int macro);

/*
** manage_map.c
*/
char			**manage_map(int macro, int hash);

/*
** manage_biome_list.c
*/
t_biome_list		*manage_biome_list(int macro);

#endif
