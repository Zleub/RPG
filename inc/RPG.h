/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPG.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 07:30:25 by adebray          ###   ########.fr       */
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
#define MAPSIZE 15
#define STRING char*

typedef struct				s_calendar_list
{
	char					*event;
	int						time;
	struct s_calendar_list	*next;
}							t_calendar_list;

typedef struct				s_biome_tree
{
	char					*biome;
	int						data;
	struct s_biome_tree		*next;
	struct s_biome_tree		*top;
	int						id;
}							t_biome_tree;

typedef struct				s_biome_conf
{
	char					*biome;
	int						id;
	short					color;
	char					character;
	struct s_biome_conf		*next;
}							t_biome_conf;

typedef struct				s_bpoint_list
{
	int						x;
	int						y;
	int						id;
	int						type;
	struct s_bpoint_list	*next;
}							t_bpoint_list;

typedef struct				s_heros
{
	char					*name;
	char					*location;
	int						level;
	int						experience;
	int						strength;
	int						stamina;
	int						agility;
	int						dexterity;
	int						intelligence;
	int						charisma;
	int						wisdom;
	int						will;
	int						life;
	int						id;
	int						cmp;
	int						ticks;
	int						age;
	char					*job;
	t_calendar_list			*state;
}							t_heros;

typedef struct				s_heros_list
{
	t_heros					*heros;
	struct s_heros_list		*next;
}							t_heros_list;

typedef struct				s_job_conf
{
	char					*name;
}							t_job_conf;

typedef struct				s_job_tree
{
	char					*job_name;
	int						id;
	struct s_job_conf		*conf;
	struct s_job_tree		*top;
	struct s_job_tree		* next;
}							t_job_tree;

typedef struct				s_gameplay
{
	int						status;
	int						count;
	int						select;
	int						run_menu;
	int						run_map;
}							t_gameplay;

enum						e_content
{
	NAME, LOCATION, LEVEL, EXPERIENCE, STRENGH, ARMOR, LIFE
};

enum						e_gameplay
{
	MENU, RUN
};

enum						e_signal
{
	SIG_WINCH, SIG_TSTP, SIG_CONT, SIG_INT
};

enum						e_biome_enum
{
	EMPTY = -1, UNIQUE, FILL, CIRCLE, RECT, LINE
};

/*
** manage_char.c
*/
t_heros						*new_char(STRING str);
t_heros						*manage_char(int macro, STRING name);


/*
** manage_game.c
*/
t_gameplay					*manage_game(int macro);
void						tick_heros(t_heros *heros);

/*
** game_new.c
*/
t_gameplay					*game_new(t_gameplay *game);
void						ft_signal(void);

/*
** game_menu.c
*/
void						game_menu(t_gameplay *game);

/*
** game_event.c
*/
void						event_vendredi(t_heros *heros);
void						event_calendar(t_heros *heros);
void						event_rand_char(t_heros *heros);

/*
** game_print.c
*/
void						print_menu(WINDOW *menu);
void						print_main(WINDOW *win);
/*
** manage_char_list.c
*/
t_heros_list				*manage_heros_list(int macro, t_heros *heros);

/*
** manage_calendar.c
*/
t_calendar_list				*manage_calendar(int macro);

/*
** manage_map.c
*/
char						**manage_map(int macro, int hash);
char						**create_map();

/*
** manage_biome_list.c
*/
t_biome_tree				*manage_biome_list(int macro);

/*
** manage_bpoint_list.c
*/
t_bpoint_list				*manage_bpoint_list(int macro, WINTAB *array);

/*
** manage_hash.c
*/
int							manage_hash(int macro, int nbr);
int							ft_hash(char *line);

/*
** manage_job.c
*/
t_job_conf					*manage_job(int macro, char *name);
void						print_job(t_job_conf *elem);

/*
** manage_job_list.c
*/
t_job_tree					*manage_job_list(int macro);

/*
** map_point.c
*/
void						collect_bpoint();

/*
** map_point_utility.c
*/
void						draw_bpoint(char **map);
int							count_gpoint(t_biome_tree *ptr);
t_biome_tree				*get_biome_ptr(char *str);
int							count_biome_top(t_biome_tree *ptr);

/*
** map_draw.c
*/
void						draw_disk(char **map, int x, int y, int bonus);
void						fill_map(char **map);
void						write_mountains(char **map, char **mountains, int biome_id);

/*
** map_mountains.c
*/
char						**create_mountains(void);
void						change_empty(char **map);
void						draw_mountains(char **map);

/*
** manage_biome_conf.c
*/
t_biome_conf				*manage_biome_conf(int macro);

#endif
