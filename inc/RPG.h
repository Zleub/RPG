/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPG.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 02:11:30 by adebray           #+#    #+#             */
/*   Updated: 2014/07/16 04:10:09 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPG_H
# define RPG_H

#include <libft.h>
#include <fcntl.h>
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

enum s_content
{
    NAME, LOCATION, LEVEL, EXPERIENCE, STRENGH, ARMOR, LIFE
};

t_heros			 *create_heros(void);
void				print_heros(t_heros *character);
void                save_heros(t_heros *character);
t_heros            *load_heros(STRING name);

#endif
