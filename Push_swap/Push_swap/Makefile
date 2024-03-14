NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE  =  Operations/*.c \
		   main.c

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o
	@rm -rf Operations/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all