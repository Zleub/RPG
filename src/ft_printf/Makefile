# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 04:54:36 by adebray           #+#    #+#              #
#    Updated: 2014/03/15 16:29:57 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADDIR = ../../inc

SRC = ./ft_atoi.c \
		./ft_isdigit.c \
		./ft_itoa.c \
		./ft_printf.c \
		./ft_putchar.c \
		./ft_putnbr.c \
		./ft_putstr.c \
		./ft_strlen.c \
		./ft_octal.c \
		./ft_hexa.c \
		./ft_sheum_hexa.c \
		./tools.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -Wuninitialized -g3 -O3
HEADFLAG = -I $(HEADDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[32m•\033[0m Printf compil: \033[32m$(NAME)\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m printf clean.\033[0m"

%.o: %.c
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m•\033[0m printf fclean: \033[31m$(NAME)\033[0m"

re: fclean all
