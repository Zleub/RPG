/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/09 07:16:06 by adebray           #+#    #+#             */
/*   Updated: 2014/08/09 14:40:39 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

t_job_conf		*create_job(void)
{
	t_job_conf	*new;

	if (!(new = (t_job_conf*)malloc(sizeof(t_job_conf))))
		return (NULL);
	new->name = NULL;
	return (new);
}

void			print_job(t_job_conf *elem)
{
	ft_printf("print_job:\n");
	ft_printf("%s\n", elem->name);
}

char			*make_path(char *name)
{
	char		*path;

	path = NULL;
	path = ft_strcatloc(path, "data/jobs/");
	path = ft_strcatloc(path, name);
	path = ft_strcatloc(path, ".job");
	return (path);
}

t_job_conf		*new_job(char *name)
{
	t_job_conf	*new;
	char		*path;

	path = make_path(name);
	if (access(path, R_OK) == -1)
	{
		ft_printf("No %s\n", path);
		return (NULL);
	}
	new = create_job();
	new->name = ft_strdup(name);
	return (new);
}

t_job_conf		*manage_job(int macro, char *name)
{
	if (macro == NEW)
		return (new_job(name));
	else
		ft_printf("Useless call to manage_job\n");
	return (NULL);
}
