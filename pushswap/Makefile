SRCS = main.c\
		helper.c\
		indexing.c\
		inputvalidation.c\
		pushes.c\
		radix.c\
		rotates.c\
		rrotates.c\
		sort.c\
		sortop.c\
		split.c\
		swapp.c\
		init.c\

OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
	  ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	   ${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all