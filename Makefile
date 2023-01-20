# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 13:25:06 by aahrach           #+#    #+#              #
#    Updated: 2023/01/19 19:18:11 by aahrach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = ./manda/ft_split.c ./manda/check_map.c ./manda/game.c \
	./manda/get_next_line.c ./manda/main.c ./manda/so_long.c \
	./manda/move.c

SRC_BONUS = ./bonus/ft_split_bonus.c ./bonus/check_map_bonus.c ./bonus/game_bonus.c \
	./bonus/get_next_line_bonus.c ./bonus/main_bonus.c ./bonus/so_long_bonus.c \
	./bonus/move_bonus.c ./bonus/textures_bonus.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

MLX = -lmlx -framework OpenGL -framework Appkit

all : ${NAME}

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(FLAGS) $(MLX) $(SRC_BONUS) -o $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLX) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
