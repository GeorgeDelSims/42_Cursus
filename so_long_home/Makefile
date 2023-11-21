NAME = so_long

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT  = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

MAKE = ar -rcs

%.o: %.c
	$(CC) -Wall -Wextra -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(MAKE) -C $(LIBFT)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re