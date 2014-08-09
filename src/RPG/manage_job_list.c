/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_job_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/09 04:30:35 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 07:39:40 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_job_tree			*create_job_list(void)
{
	t_job_tree		*new;

	if (!(new = (t_job_tree*)malloc(sizeof(t_job_tree))))
		return (NULL);
	new->job_name = NULL;
	new->id = -1;
	new->conf = NULL;
	new->top = NULL;
	new->next = NULL;
	return (new);
}

void				print_tab(int nbr)
{
	while (nbr)
	{
		ft_printf("\t");
		nbr--;
	}
}

void			print_job_tree(t_job_tree *head, int level)
{
	if (!head)
		return ;
	print_tab(level);
	ft_printf("%s", head->job_name);
	if (head->conf)
	{
		ft_printf("_");
		print_job(head->conf);
	}
	else
		ft_printf("\n");
	print_job_tree(head->top, level + 1);
	print_job_tree(head->next, level);
}

int				ft_job_count(void)
{
	static int	i;

	i += 1;
	return (i);
}

int						get_lvl(char *line)
{
	int			i;

	i = 0;
	while (line[i] == '-')
		i += 1;
	return (i);
}

char			*ft_job_extract(char *line)
{
	while (!ft_isalpha(*line))
		line += 1;
	return (ft_strdup(line));
}

void			fill_job(t_job_tree **elem, char *line)
{
	(*elem) = create_job_list();
	(*elem)->job_name = ft_job_extract(line);
	(*elem)->id = ft_job_count();
	(*elem)->conf = manage_job(NEW, (*elem)->job_name);
}

void			insert_next_job(t_job_tree *head, char *line)
{
	int			i;

	i = get_lvl(line);
	while (head->next)
	{
		head = head->next;
	}
	while (head->top && i)
	{
		head = head->top;
		while (head->next)
			head = head->next;
		i--;
	}
	if (i != 0)
		fill_job(&head->top, line);
	else
		fill_job(&head->next, line);
}

t_job_tree		*fill_job_list(int fd)
{
	t_job_tree	*head;
	char		*line;

	head = NULL;
	get_next_line(fd, &line);
	fill_job(&head, line);

	while (get_next_line(fd, &line))
		insert_next_job(head, line);
	return (head);
}

t_job_tree		*new_job_list(void)
{
	t_job_tree	*head;
	int			fd;

	if (access("data/job_list", R_OK) == -1)
	{
		ft_printf("No job list\n");
		return (NULL);
	}
	fd = open("data/job_list", O_RDONLY);

	head = fill_job_list(fd);

	close(fd);
	return (head);
}

t_job_tree		*manage_job_list(int macro)
{
	static t_job_tree	*head;

	if (macro == GET)
		return (head);
	else if (macro == NEW)
		head = new_job_list();
	else if (macro == PRINT)
		print_job_tree(head, 0);
	else
		ft_printf("Useless call to manage_job_list\n");
	return (NULL);
}
