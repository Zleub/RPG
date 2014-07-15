#ifndef CURSE_H
# define CURSE_H

#include <ncurses.h>
#include <ft_printf.h>
#include <stdlib.h>

enum	e_manage
{
	GET, SET, NEW
};

WINDOW    *manage_ncurses(int macro);
WINDOW    *manage_win_list(int macro, WINDOW *object);
WINDOW	*manage_win(int macro, WINDOW *object);


#endif
