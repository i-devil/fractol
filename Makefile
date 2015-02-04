
NAME	= fractol
SRC		= main.c mandelbrot.c hook.c color.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
FLAGS	= #-Wall -Wextra #-Werror
MLX	= -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@$(CC) -I /usr/X11/include $(OBJ) -o $(NAME) -L libft/ -lft $(FLAGS)

%.o: %.c
	@$(CC) -I /usr/X11/include -I . -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
