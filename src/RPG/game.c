#include <RPG.h>

void        taverne(t_heros *character)
{
    char    *str;

    ft_printf("You are in the tavern.\n");
    ft_printf("(S)leep.\n");
    ft_printf("Go (H)unt.\n");
    ft_printf("(S)hop.\n");
    if (!(get_next_line(1, &str)))
        return (0);

}

void        game(t_heros *character)
{
    if (!ft_strcmp(character->location, "Taverne"))
        taverne(character);
}
