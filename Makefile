
CC = clang
CFLAGS = -Wall -Wextra
CPPFLAGS = -iquote "./include"

SRC = ./src/main.c \
			./src/globals.c \
			./src/stack_alloc.c \
			./src/stack_free.c \
			./src/tools.c
OBJ = $(SRC:.c=.o)

NAME = heap

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) -o $(NAME)
