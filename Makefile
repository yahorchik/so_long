# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayshok <mayshok@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 16:08:45 by seulah            #+#    #+#              #
#    Updated: 2022/02/16 16:51:20 by mayshok          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re make norm

NAME = so_long

SRCS =	./src/so_long.c\
		./src/so_long_utils.c\
		./src/so_long_utils_2.c\
		./src/so_long_error.c\
		./src/so_long_loop.c\
		./src/ft_split.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\

HEAD = ./inc/so_long.h		./inc/so_long_keys.h
OBJ = $(patsubst %.c, %.o, $(SRCS))

CC = gcc

FLAGS = -Wall -Wextra -Werror

SO_LONG_FLAGS = -framework OpenGL -framework AppKit

OPTFLAGS = -O2

all : $(NAME)


*%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -I inc/ -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
