NAME		=	philo
OBJS_DIR	=	./objs
SRCS_DIR	=	.

HEADERS		=	./philo.h

SRC_FILES	=	main.c utils.c philo.c simulation.c \
				monitor.c daily.c write_stuff.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

CFLAGS		= -Wall -Wextra -Werror
CFLAGS_H	= -MMD -MP
RM			= rm -f
CC			= gcc

all:		$(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	${CC} $(CFLAGS) $(CFLAGS_H) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

${NAME}: 	${OBJS}
	${CC} $(CFLAGS) $(CFLAGS) -o ${NAME} -lpthread ${OBJS}

clean:
				$(RM) $(OBJS) $(DEPS)
				rm -rf $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
