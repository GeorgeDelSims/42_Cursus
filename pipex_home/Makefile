NAME = pipex

SOURCES	= ./srcs/main.c ./srcs/parsing.c ./srcs/access.c ./srcs/utils.c ./srcs/processes.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = ./libft

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L./libft -lft

$(LIBFT)/libft.a:
	make -C $(LIBFT)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re