SRCS			=	get_next_line.c get_next_line_utils.c \

SRCS_BONUS		=	get_next_line_bonus.c get_next_line_utils_bonus.c\


OBJS		=	${SRCS:.c=.o}
BONUS_OBJ	=	${SRCS_BONUS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):  $(OBJS)
				ar rcs $@ $^

clean:
				$(RM) $(OBJS) $(BONUS_OBJ)

fclean:			clean
				$(RM) $(NAME) $(BONUS_OBJ)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJ)
				ar rcs ${NAME} $(OBJS) $(BONUS_OBJ)

.PHONY:			all clean fclean re