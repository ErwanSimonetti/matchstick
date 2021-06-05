##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC		=	gcc

SRC			=	source/matchstick.c			\
				source/check_errors.c		\
				source/write_sticks.c		\
				source/sticks.c				\
				source/sub_sticks.c 		\
				source/sub_player_sticks.c	\
				source/line_empty.c 		\
				source/remove_back_n.c 		\
				source/game_lost.c 			\
				source/ai_turn.c 			\
				source/game.c

NAME		=	matchstick

LIB_MY		=	libmy.a

CFLAGS		=	-Wall -Wextra -pedantic

LDFLAGS		=	-L./lib -lmy

CPPFLAGS	=	-I./include -g3

all:	binary

$(LIB_MY):
		@make -sC lib/my/

binary:	$(LIB_MY)
		@$(CC) -o $(NAME) $(SRC) main.c $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)
		@echo -e "\033[05m\033[44mcompilation done => ${NAME}\033[00m"

clean:
		make -sC lib/my/ clean

fclean:	clean
		make -sC lib/my/ fclean
		rm -f $(NAME)
		clear

re:	fclean all

.PHONY:	clean fclean re all
