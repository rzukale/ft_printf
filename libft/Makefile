# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 15:23:58 by rzukale           #+#    #+#              #
#    Updated: 2022/06/18 18:04:00 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_atoi.c           \
        ft_isdigit.c        \
        ft_itoa.c		\
        ft_memset.c		\
        ft_putchar.c	\
        ft_putendl.c	\
        ft_putnbr.c		\
        ft_putstr.c		\
        ft_strdel.c		\
        ft_strdup.c		\
        ft_strjoin.c	\
        ft_strlen.c		\
        ft_strncat.c	\
        ft_strnew.c		\
        ft_isspace.c	\
        ft_abs.c        \
        ft_itoa_base.c  \
        ft_int_length.c	\
		ft_strjoin_freeable.c

OBJ = $(SRC:.c=.o)
SRC_DIR = srcs
OBJ_DIR = objs
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
HEADER = -I includes
CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): $(SRCS)
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(SRCS) $(HEADER)
	mv $(OBJ) $(OBJ_DIR)

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.PRECIOUS: author
