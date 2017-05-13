# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 16:55:36 by liabanzh          #+#    #+#              #
#    Updated: 2017/03/20 16:55:38 by liabanzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = lem_in
CC = gcc
SRC = src/lem.c
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all re clean fclean

all: $(NAME1)

$(NAME1): $(LIB) $(SRC:.c=.o)
	$(CC) -o $(NAME1) $(SRC:.c=.o) $(FLAGS) $(LIB)
	
$(LIB):
	make -C ./libft

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	make clean -C ./libft
	rm -f $(SRC:.c=.o) $(MAIN1:.c=.o)

fclean: clean
	rm -f $(LIB) $(NAME1)
	
re: fclean all
