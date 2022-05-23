# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/05/23 11:59:56 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = get_next_line.h
LIB = ar -rcs
SRCS =  so_long.c
OBJS = ${SRCS:.c=.o}
BONUS =
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
CFLAGS :=-Wall -Wextra -Werror -D BUFFER_SIZE=42 -fsanitize=address
RM = rm -f

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(SRCS) -L. -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I./ -o $(NAME) && ./so_long

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
