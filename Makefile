 NAME = ft_printf.a

SRCS = ft_printf.c ft_print_str.c ft_print_ptr.c ft_print_number.c \
ft_print_unsigned.c ft_print_hexa.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CC_FLAGS} -g -c $< -o ${<:.c=.o}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re