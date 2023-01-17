# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 13:25:06 by aahrach           #+#    #+#              #
#    Updated: 2023/01/16 22:18:15 by aahrach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = ft_split.c check_map.c game.c get_next_line.c main.c so_long.c move.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLX) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
