# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 16:36:18 by liabanzh          #+#    #+#              #
#    Updated: 2016/11/27 16:36:20 by liabanzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
F = -Wall -Wextra -Werror
SOURCE = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c  ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_putchar.c ft_putstr.c \
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_print_matrix.c ft_is_square.c ft_change.c ft_power.c ft_rot.c \
	ft_most_visible.c ft_atoi_base.c get_next_line.c ft_itoa_base.c \
	ft_str_toupper.c ft_realloc.c ft_atoi_long.c

OBJ = $(SOURCE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(F) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all