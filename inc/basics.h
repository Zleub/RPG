/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 11:39:02 by adebray           #+#    #+#             */
/*   Updated: 2014/07/05 10:40:42 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
// # include <basics.h>
# include <math.h>

/*
** point.c
*/

# define FOREACH

# define POINT int*

int						*makepoint(int x, int y);
void					printpoint(POINT array);

/*
** pointlist.c
*/

typedef struct			s_pointlist
{
	POINT				content;
	struct s_pointlist	*next;
}						t_pointlist;

t_pointlist				*newpointlist(void);
t_pointlist				*addpointlist(POINT array, t_pointlist *list);
void					printpointlist(t_pointlist *list);
void					managepointlist(char *macro, POINT value);

/*
** basics.c
*/

int						moveto(POINT array);

/*
** draw.c
*/

int						drawpix(POINT pix);
int						drawrect(POINT size);

/*
** manage.c
*/

void					*managemlx(char *macro);
void					*managewin(char *macro, POINT size, char *name);
POINT					managelocation(char *macro, POINT value);
char					*manageimage(char *macro, POINT value);
int						managecolor(char *macro, int value);

#endif
