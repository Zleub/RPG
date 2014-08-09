#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:21:22 by adebray           #+#    #+#              #
#    Updated: 2014/03/11 06:45:07 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libRPG.a
LIB			=	ft
HEADDIR		=	 ../../inc

SRC			=	game_event.c \
				game_menu.c \
				game_new.c \
				game_print.c \
				manage_biome_conf.c \
				manage_biome_list.c \
				manage_bpoint_list.c \
				manage_calendar.c \
				manage_char.c \
				manage_char_list.c \
				manage_game.c \
				manage_hash.c \
				manage_job.c \
				manage_job_list.c \
				manage_map.c \
				map_draw.c \
				map_mountains.c \
				map_point.c \
				map_point_utility.c \
				signal.c

OBJ			= $(subst .c,.o,$(SRC))

CC		= gcc
CCFLAGS	= -Werror -Wall -Wextra -Wuninitialized -O3 -g

all: $(NAME)

$(NAME):	$(OBJ)
			@ar rc $@ $^
			@ranlib $@
			@echo '!'
			@echo "\033[32m•\033[0m RPG compil: \033[32m$(NAME)\033[0m"

%.o:		%.c $(HEADDIR)/RPG.h
			@echo '.''\c'
			@$(CC) $(CCFLAGS) -I $(HEADDIR) -o $@ -c $<

clean:
			@rm -f $(OBJ)
			@echo "\033[31m•\033[0m rpg clean.\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[31m•\033[0m rpg fclean: \033[31m$(NAME)\033[0m"

re:			all

.PHONY: all clean fclean re
