# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboute <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 20:02:22 by nboute            #+#    #+#              #
#    Updated: 2017/01/10 18:15:27 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = fdf

LIB = -L libft/ -lft

LIBFT = libft/libft.a

MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBMLX = minilibx_macos/mlx.a

CFLAGS = -c -Wall -Wextra -Werror

OPTI = -O2 -march=native

WFLAGS = -Wall -Wextra -Werror

CC = gcc

C_DIR = srcs/

SRCS = main.c \
	   ft_setup.c \
	   ft_repeat.c \
	   ft_rotate.c \
	   ft_actions.c \
	   ft_draw.c \
	   ft_colors.c \
	   ft_sort.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I libft/


all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OPTI) $(WFLAGS) $(MLX) $^ -o $@ $(LIB)

$(LIBFT):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $^ $(INC)

clean :
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(LIBMLX)
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
