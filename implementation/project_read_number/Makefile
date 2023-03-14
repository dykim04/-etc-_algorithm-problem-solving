NAME = read_number
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/
OBJS = ${SRCS}01.main.o ${SRCS}02.ft_split.o ${SRCS}03.linked_list.o ${SRCS}04.numeric_data_type.o ${SRCS}05.solve.o ${SRCS}06.memory.o ${SRCS}07.validation.o 

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

.c.o :
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
