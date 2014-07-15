#ifndef RPG_H
# define RPG_H

#include <libft.h>
#include <fcntl.h>
#include <stdio.h>

#define STRING char*

typedef struct		s_heros
{
    STRING			name;
    STRING          location;
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

t_heros				*create_heros(void);
void				print_heros(t_heros *character);
void                save_heros(t_heros *character);
t_heros            *load_heros(STRING name);

#endif
