/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 14:52:25 by adebray           #+#    #+#             */
/*   Updated: 2014/07/15 20:12:06 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPG.h>

int					ft_hash(char *line)
{
	int				hash;
	int				c;

	hash = 5381;
	while ((c = *line++))
		hash = ((hash << 5) + hash) ^ c;
	if (hash < 0)
		return (hash * -1);
	else
		return (hash);
}

void				new_char(STRING str)
{
	t_heros			*main_char;
	int				hash;

	main_char = create_heros();
	hash = ft_hash(str);
	main_char->name = str;
	main_char->location = "Taverne";
	main_char->experience = 0;
	main_char->level = 0;
	main_char->armor = 0;
	main_char->strengh = hash % 21;
	main_char->life = 20;
	save_heros(main_char);
}

#include <curse.h>

int					main(void)
{
	// STRING			str;
	// t_heros			*load_char;

	// printf("Hi. What's your name ?\n");
	// if (!(get_next_line(1, &str)))
	// 	return (0);
	// if ((load_char = load_heros(str)) != NULL)
	// 	print_heros(load_char);
	// else
	// 	new_char(str);
	// return (0);

	WINDOW		*mainwin;

	if ((mainwin = initscr()) == NULL)
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	manage_ncurses(SET);

	manage_win(NEW, create_wintab(10, 10, 0, 0));


	sleep(1);
	endwin();
	delwin(manage_ncurses(GET));
	refresh();
	return (0);
}
