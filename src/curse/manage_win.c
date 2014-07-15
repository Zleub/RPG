#include <curse.h>

WINDOW	*manage_win(int macro, WINDOW *object)
{
	static WINDOW	*ptr;

	if (macro == GET)
		return (ptr);
	else if (macro == SET)
		ptr = object;
	else if (macro == NEW)
	{
		;
	}
	return (NULL);
}
