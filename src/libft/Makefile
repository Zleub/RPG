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

NAME		=	libft.a
LIB			=	ft
HEADDIR		=	 ../../inc

SRC			=	ft_memset.c				ft_bzero.c			ft_memcpy.c		\
				ft_memccpy.c			ft_memmove.c		ft_memchr.c		\
				ft_memcmp.c				ft_strlen.c			ft_strdup.c		\
				ft_strcpy.c				ft_strncpy.c		ft_strcat.c		\
				ft_strncat.c			ft_strlcat.c		ft_strchr.c		\
				ft_strrchr.c			ft_strstr.c			ft_strnstr.c	\
				ft_strcmp.c				ft_strncmp.c		ft_atoi.c		\
				ft_isalpha.c			ft_isdigit.c		ft_isalnum.c	\
				ft_isascii.c			ft_isspace.c		ft_isprint.c	\
				ft_tolower.c			ft_toupper.c		ft_memalloc.c	\
				ft_memdel.c				ft_strnew.c			ft_strdel.c		\
				ft_strclr.c				ft_striter.c		ft_striteri.c	\
				ft_strmap.c				ft_strmapi.c		ft_strequ.c		\
				ft_strnequ.c			ft_strsub.c			ft_strjoin.c	\
				ft_strtrim.c			ft_strsplit.c		ft_itoa.c		\
				ft_putchar.c			ft_putstr.c			ft_putendl.c	\
				ft_putnbr.c				ft_putchar_fd.c		ft_putstr_fd.c	\
				ft_putnbr_fd.c			ft_putendl_fd.c		all_free.c		\
				ft_strndup.c			ft_strclen.c		gnl.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -O3 -g3

all: $(NAME)

$(NAME):	$(OBJ)
			@ar rc $@ $^
			@ranlib $@
			@echo "\033[32m•\033[0m Libft compil: \033[32m$(NAME)\033[0m"

%.o:		%.c
			@$(CC) $(CCFLAGS) -I $(HEADDIR) -o $@ -c $<

clean:
			@rm -f $(OBJ)
			@echo "\033[31m•\033[0m libft clean.\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[31m•\033[0m libft fclean: \033[31m$(NAME)\033[0m"

re:			all

.PHONY: all clean fclean re
