# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/06/19 18:40:42 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = -I./
SRCS = so_long.c check_map.c load_game_images.c get_next_line.c get_next_line_utils.c player_move.c event_handler.c make_window.c error_handling.c
OBJS = ${SRCS:.c=.o}
OBJS_T = so_long_tester.o
CC = gcc
CFLAGS :=-Wall -Wextra -Werror -DBUFFER_SIZE=42 -fsanitize=address
RM = rm -f

all:linux

$(NAME): ${OBJS} libftprintf.a
	$(CC) $(OBJS) -L./ -lftprintf -I./ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

linux: $(OBJS) libftprintf.a
	$(CC) $(OBJS) -L./ -lftprintf -I./  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o linux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -DBUFFER_SIZE=42 -I/usr/include -Imlx_linux -O3 -c $< -o $@

test:${OBJS} ${OBJS_T}
	${CC} ${CFLAGS} so_long_tester.c ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./ -L. -lft -o tester

fetch:
	${MAKE} -C ../printf42
	mv ../printf42/libftprintf.a /Users/atereso-/Documents/so_long_home
	${MAKE} -C ../printf42 clean
	${MAKE} -C ../printf42/libft clean

libftprintf.a:
	${MAKE} -C ../printf42
	mv ../printf42/libftprintf.a /home/afonso/Documents/GitHub/so_long_home
	${MAKE} -C ../printf42 clean
	${MAKE} -C ../printf42/libft clean

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} libftprintf.a
	${RM} linux
	${RM} tester

re: fclean all

.PHONY: all re clean fclean bonus fetch fetchl
