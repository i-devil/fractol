# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 18:15:51 by ide-vill          #+#    #+#              #
#    Updated: 2014/11/27 19:13:13 by ide-vill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strclr.c \
		  ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strsplit.c \
		  ft_strtrim.c \
		  ft_atoi.c ft_itoa.c \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_toupper.c ft_tolower.c \
		  ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_lstdel.c ft_lstiter.c ft_lstnew.c ft_lstadd.c ft_lstdelone.c \
		  ft_lstpushback.c  ft_lstsmartpushback.c ft_lstsimpledel.c \
		  ft_lstsimpledelone.c get_next_line.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
HEADER	= includes/
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c
	@$(CC) -I $(HEADER) -o $@ -c $? $(FLAGS)

.PHONY: clean fclean re

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
