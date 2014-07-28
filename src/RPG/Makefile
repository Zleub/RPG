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

SRC			=	manage_game.c \
				game_new.c \
				game_menu.c \
				manage_char.c \
				manage_char_list.c \
				signal.c

OBJ			= $(subst .c,.o,$(SRC))

CC		= gcc
CCFLAGS	= -Werror -Wall -Wextra -Wuninitialized -O0 -g

# LIBFLAGS = -lncurses

all: $(NAME)

$(NAME):	$(OBJ)
			@ar rc $@ $^
			@ranlib $@
			@echo "\033[32m•\033[0m RPG compil: \033[32m$(NAME)\033[0m"

%.o:		%.c
			@$(CC) $(CCFLAGS) -I $(HEADDIR) -o $@ -c $<

clean:
			@rm -f $(OBJ)
			@echo "\033[31m•\033[0m rpg clean.\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[31m•\033[0m rpg fclean: \033[31m$(NAME)\033[0m"

re:			all

.PHONY: all clean fclean re
