/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/01 19:30:02 by adebray           #+#    #+#             */
/*   Updated: 2014/07/01 19:31:09 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

t_pointlist	*newpointlist(void)
{
	t_pointlist		*elem;

	elem = malloc(sizeof(t_pointlist));
	elem->content = NULL;
	elem->next = NULL;
	return (elem);
}

void		printpointlist(t_pointlist *list)
{
	while (list)
	{
		ft_printf("printpointlist:\n");
		ft_printf("list->content[0]: %d\n", list->content[0]);
		ft_printf("list->content[1]: %d\n", list->content[1]);
		list = list->next;
	}
}

t_pointlist	*addpointlist(POINT array, t_pointlist *list)
{
	t_pointlist		*ptr;

	ptr = list;
	if (!list)
	{
		list = newpointlist();
		list->content = array;
		return (list);
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = newpointlist();
		list->next->content = array;
		return (ptr);
	}
}

void		managepointlist(char *macro, POINT value)
{
	static t_pointlist	*list;

	if (!strcmp(macro, "add"))
		list = addpointlist(value, list);
	else if (!strcmp(macro, "print"))
		printpointlist(list);
	else
		ft_printf("Useless managepointlist call\n");
}
