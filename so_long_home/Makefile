NAME = so_long

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

%.o: %.c
	$(CC) -Wall -Wextra -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re