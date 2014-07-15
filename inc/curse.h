#ifndef CURSE_H
# define CURSE_H

# include <ncurses.h>
# include <ft_printf.h>
# include <stdlib.h>

enum	e_manage
{
	GET, SET, NEW, ADD
};

# define WINTAB			int*

typedef struct	s_wintab_list
{
	int				*array;
	s_wintab_list	*next;
}				t_wintab_list;

# define WINTABLIST		t_wintab_list*

WINDOW	*manage_ncurses(int macro);
WINDOW	*manage_win_list(int macro, WINDOW *object);
WINDOW	*manage_win(int macro, WINDOW *object);
WINTAB	create_wintab(int i, int j, int x, int y);

#endif
