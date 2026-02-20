NAME = philo

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = main.c \
	parsing.c \
	init.c \
	time.c \
	routing.c \
	monitor.c

OBJ = $(SRC:.c=.o)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
