/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/19 02:31:23 by adebray           #+#    #+#             */
/*   Updated: 2014/07/28 12:11:24 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_heros_list	*create_heros_list(void)
{
	t_heros_list	*new;

	if (!(new = (t_heros_list*)malloc(sizeof(t_heros_list))))
		return (NULL);
	new->heros = NULL;
	new->next = NULL;
	return (new);
}

t_heros_list	*load_heros_list(t_heros_list *head, char *name)
{
	int		fd;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	else
	{
		(void)head;
		(void)name;
	}
	return (head);
}

t_heros_list	*add_heros_list(t_heros_list *head, t_heros *heros)
{
	t_heros_list	*tmp;

	if (!head)
	{
		head = create_heros_list();
		head->heros = heros;
	}
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_heros_list();
		tmp->next->heros = heros;
	}
	manage_game(GET)->count += 1;
	return (head);
}

t_heros_list	*manage_heros_list(int macro, t_heros *heros)
{
	static t_heros_list	*head;

	if (macro == GET)
		return (head);
	// else if (macro == SET)
	// 	heros = new_heros;
	else if (macro == LOAD)
	{
		if (!(head = load_heros_list(head, heros->name)))
			return (NULL);
		else
			return (head);
	}
	else if (macro == ADD)
		head = add_heros_list(head, heros);
	else
		ft_printf("useless call to manage_heros_list\n");
	return (NULL);
}
