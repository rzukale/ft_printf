# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 21:00:35 by rzukale           #+#    #+#              #
#    Updated: 2022/06/20 01:43:56 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	ft_printf.c					\
		ft_printf_char.c			\
		ft_printf_double.c			\
		ft_printf_percent.c			\
		ft_printf_pointer.c			\
		ft_printf_signed_int.c		\
		ft_printf_str.c				\
		ft_printf_unsigned_int.c	\
		ft_printf_flags.c			\
		ft_printf_utils.c			\
		ft_printf_unsigned_int_utils.c	\
		ft_printf_double_utils.c		\
		ft_printf_pointer_utils.c		\
		ft_printf_sint_utils.c

OBJ = $(SRC:.c=.o)
SRC_DIR = src
OBJ_DIR = obj
LIBFT = libft
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
HEADER = include
CFLAGS = -Wall -Wextra -Werror -O3 -I
CC = gcc

all: $(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "ft_printf object files removed"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Removed executables/lib files"

re: fclean all

norm:
	@norminette $(LIBFT) $(SRC_DIR) $(HEADER)

.PHONY: all clean fclean re norm
