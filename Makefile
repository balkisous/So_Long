# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:25:05 by bben-yaa          #+#    #+#              #
#    Updated: 2021/11/15 16:45:24 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=./srcs/get_next_line/get_next_line.c \
		./srcs//get_next_line/get_next_line_utils.c \
		./srcs/main/main.c \
		./srcs/main/main_utils.c \
		./srcs/parsing/parsing.c \
		./srcs/parsing/parsing_map.c \
		./srcs/parsing/parsing_utils.c \
		./srcs/draw/init_game.c \
		./srcs/draw/draw_map.c \
		./srcs/draw/place_and_move.c \
		./srcs/draw/mlx_utils.c \
		./srcs/draw/draw_texture.c \
		./srcs/draw/exit_game.c

SO_LONG	= so_long

OBJ		= $(SRCS:.c=.o)
RM		= rm -rf
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

.c .o:
		$(CC) $(FLAGS) -Imlx -Lmlx -lmlx -O3 -c $< -o $@ 

$(SO_LONG): $(OBJ)
				make -C mlx
				$(CC) $(FLAGS) $(OBJ)  -Imlx -Lmlx -lmlx -Imlx -lXext -lX11 -lm -o ${SO_LONG}
			
all		: ${SO_LONG}

clean	:
				${RM} ${OBJ}

fclean	:	clean
				${RM} ${SO_LONG}

re		:	fclean all

.PHONY : all clean fclean re
