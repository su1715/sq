SRCS = main.c dynamic.c ft_exit.c ft_read_first_line.c ft_read_first_row.c ft_read_grid.c input.c print_map.c str_realloc.c util.c util2.c
CC	 = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
NAME = BSQ

all : $(NAME)

$(NAME) : ${SRCS} ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : clean fclean re ${NAME} all