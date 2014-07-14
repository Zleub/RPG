# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/16 14:40:42 by adebray           #+#    #+#              #
#    Updated: 2014/07/09 04:42:18 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	RPG
HEADDIR		=	inc

SRC			=	./src/main.c
OBJ			=	$(subst .c,.o,$(SRC))

XOBJ		=	$(shell ls ./src/minilibx | grep '\.o')
XLIB		=	$(shell ls ./src/minilibx | grep '\.a')

CC			=	clang
CCFLAGS		=	-Werror -Wall -Wextra -Wuninitialized -g3 -O3

HEADFLAG	=	-I ./$(HEADDIR)

LIBLIBFT	=	-L./src/libft -lft
LIBPRINTF	=	-L./src/ft_printf -lftprintf
LIBESSENTIAL =	$(LIBLIBFT) $(LIBPRINTF)

LIBRPG		=	-L./src/RPG -lRPG

LIBBASIC	=	-L./src/basics -lbasic
LIBX11		=	-L/usr/X11/lib -lXext -lX11
LIBMLX		=	-L./src/minilibx -lmlx
LIBGRAPHIC	=	$(LIBX11) $(LIBBASIC) $(LIBMLX) -lncurses

LIBFLAG		=	$(LIBESSENTIAL) $(LIBGRAPHIC) $(LIBRPG)

.PHONY: all clean fclean re ultragcc

all: $(NAME)

makelib: minilibx libft printf libbasic librpg

$(NAME): makelib $(OBJ)
	@$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) $(OBJ)
	@echo "\033[32m•\033[0m $(NAME) compil: \033[32m$(NAME)\033[0m"

libft: ./inc/libft.h
	@make -C ./src/libft

libbasic: ./inc/basics.h
	@make -C ./src/basics

printf: ./inc/ft_printf.h
	@make -C ./src/ft_printf

minilibx: ./inc/mlx.h
	@make -C ./src/minilibx

librpg: ./inc/RPG.h
	@make -C ./src/RPG

%.o: %.c ./inc/RPG.h
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	@make -C ./src/libft clean
	@make -C ./src/basics clean
	@make -C ./src/ft_printf clean
	@make -C ./src/minilibx clean
	@make -C ./src/RPG clean
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m $(NAME) clean.\033[0m"

fclean:
	@(cd ./src/minilibx; rm -rf $(XOBJ))
	@(cd ./src/minilibx; rm -rf $(XLIB))
	@make -C ./src/libft fclean
	@make -C ./src/basics fclean
	@make -C ./src/ft_printf fclean
	@make -C ./src/RPG fclean
	@rm -f $(OBJ)
	@rm -f $(LIBNAME)
	@rm -f $(NAME)
	@echo "\033[31m•\033[0m $(NAME) fclean: \033[31m$(NAME)\033[0m"

re: fclean all
