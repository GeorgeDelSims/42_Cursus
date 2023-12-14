NAME = pipex

SOURCES	= ./srcs/main.c ./srcs/parsing.c ./srcs/utils.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re