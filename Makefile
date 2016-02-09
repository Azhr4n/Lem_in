# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 15:30:43 by pivanovi          #+#    #+#              #
#    Updated: 2014/03/15 03:42:11 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = lem-in

SRC =	list/list_init.c			\
		list/tools_list.c			\
		list/parser1.c				\
		checks/check_command.c		\
		checks/check_room.c			\
		checks/check_ants.c			\
		checks/check_pipe.c			\
		tools/get_next_line.c		\
		tools/ft_strsplit.c			\
		tools/ft_strjoin.c			\
		tools/ft_putchar.c			\
		tools/fill_tab_i.c			\
		tools/del_space.c			\
		tools/ft_strdup.c			\
		tools/ft_putstr.c			\
		tools/ft_putnbr.c			\
		tools/ft_strcmp.c			\
		tools/ft_strlen.c			\
		tools/free_tab.c			\
		tools/ft_zfill.c 			\
		tools/nb_args.c				\
		tools/ft_atoi.c				\
		road/tools.c				\
		ants/ants.c					\
		lem-in.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
