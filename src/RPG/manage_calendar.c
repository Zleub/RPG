/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_calendar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/04 03:21:53 by adebray           #+#    #+#             */
/*   Updated: 2014/08/05 21:11:45 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_calendar_list		*create_calendar(void)
{
	t_calendar_list		*new;

	if (!(new = (t_calendar_list*)malloc(sizeof(t_calendar_list))))
		return (NULL);
	new->event = NULL;
	new->time = -1;
	new->next = NULL;
	return (new);
}

t_calendar_list		*new_calendar(void)
{
	int					fd;
	int					i;
	char				*buffer;
	t_calendar_list		*head;
	t_calendar_list		*tmp;

	if (access("data/calendar", R_OK) == -1)
		return (NULL);
	fd = open("data/calendar", O_RDONLY);
	get_next_line(fd, &buffer);
	i = 0;
	while (buffer[i] != ':')
		i += 1;

	head = create_calendar();

	head->event = ft_strndup(buffer, i);
	head->time = ft_atoi(buffer + i + 1);

	tmp = head;

	while (get_next_line(fd, &buffer) != 0)
	{
		tmp->next = create_calendar();
		tmp = tmp->next;
		i = 0;
		while (buffer[i] != ':')
			i += 1;
		tmp->event = ft_strndup(buffer, i);
		tmp->time = ft_atoi(buffer + i + 1);
		tmp->next = head;
	}

	close(fd);
	return (head);
}

void				print_calendar(t_calendar_list *head)
{
	if (!head)
	{
		ft_printf("No calendar to print\n");
		return ;
	}
	while (head)
	{
		ft_printf("print_calendar: \n");
		ft_printf("%s\n", head->event);
		ft_printf("%d\n", head->time);
		head = head->next;
	}
}

t_calendar_list		*manage_calendar(int macro)
{
	static t_calendar_list		*head;

	if (macro == GET)
		return (head);
	// else if (macro == SET)
	// 	heros = new_heros;
	// else if (macro == LOAD)
	// 	load_heros(name);
	else if (macro == NEW)
		head = new_calendar();
	else if (macro == PRINT)
		print_calendar(head); // INFINT LOOP DUE TO CIRCULAR LIST
	else
		ft_printf("useless call to manage_calendar\n");
	return (NULL);
}
