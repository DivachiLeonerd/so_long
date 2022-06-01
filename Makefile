# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/06/01 15:51:41 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = get_next_line.h
LIB = ar -rcs
SRCS =  so_long.c check_map.c load_game_images.c get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
BONUS =
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
CFLAGS :=-Wall -Wextra -Werror -DBUFFER_SIZE=42 -fsanitize=address
RM = rm -f

$(NAME):${OBJS}
	$(CC) ${CFLAGS} $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./ -L. -lft -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -DBUFFER_SIZE=42 -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:
	${CC} ${FLAGS} ${SRCS} -I.

bonus: ${OBJS} ${BONUS_OBJS}
		${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.${HEADER}

	mv a.out tester
	./tester
clean:
	${RM} ${OBJS}
	${RM} tester

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
