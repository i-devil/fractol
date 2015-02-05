# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 11:51:33 by ide-vill          #+#    #+#              #
#    Updated: 2015/02/04 11:51:43 by ide-vill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
SRC		= main.c hook.c color.c draw.c mandelbrot.c julia.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@$(CC) $(OBJ) -o $(NAME) -L libft/ -lft $(FLAGS) -g

%.o: %.c
	@$(CC) -I . -o $@ -c $? $(FLAGS) -g

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
