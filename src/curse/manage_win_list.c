#include <curse.h>

WINDOW    *manage_win_list(int macro, WINDOW *object)
{
    static WINDOW    *head;

    if (macro == GET)
        return (head);
    else if (macro == SET)
        head = object;
    else if (macro == NEW)
    {
        ;
    }
    return (NULL);
}
