# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meyami <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 22:14:03 by meyami            #+#    #+#              #
#    Updated: 2018/01/05 22:14:06 by meyami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/meyami.filler
DIR_LIB = libft
SRC = main.c tab.c piece.c player.c reader.c cell.c trim.c
BINARIES = $(SRC:.c=.o)
CC = gcc -Wall -Werror -Wextra

all: $(DIR_LIB) $(NAME)

$(NAME):  $(BINARIES)
	$(CC) $(BINARIES) -o $(NAME) -I libft/includes -L $(DIR_LIB) -lft

$(DIR_LIB): libft.a

libft.a:
	$(MAKE) -C $(DIR_LIB)

%.o: %.c
	$(CC) -c $<

clean:
	$(MAKE) -C $(DIR_LIB) clean
	/bin/rm -f $(BINARIES)
fclean: clean
	$(MAKE) -C $(DIR_LIB) fclean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re%
