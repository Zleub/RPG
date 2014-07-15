#include <curse.h>

WINDOW    *manage_ncurses(int macro)
{
    static WINDOW    *main_win;

    if (macro == GET)
        return (main_win);
    else if (macro == SET)
    {
        if ((main_win = initscr()) == NULL)
        {
            ft_printf("Error initialising ncurses.\n");
            exit(0);
        }
    }
    else if (macro == NEW)
    {
        ;
    }
    return (NULL);
}
