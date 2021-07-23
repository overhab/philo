NAME		=	test # change to "philo"
OBJS		=	$(SRCS:.c=.o)
SRC_DIR		=	.

HEADERS		=	./philo.h

SRCS		=	./main.c ./utils.c ./philo.c ./simulation.c \
				./monitor.c ./daily.c ./write_stuff.c

CFLAGS	= #-Wall -Wextra -Werror
RM		= rm -f
CC		= clang

all:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	${CC} $(CFLAGS) -c $< -o $@

${NAME}: 	${OBJS}
	${CC} -o ${NAME} -lpthread ${OBJS}


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
