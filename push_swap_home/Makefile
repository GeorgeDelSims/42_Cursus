NAME = push_swap

SOURCES = ./srcs/main.c ./srcs/operations.c ./srcds/utils.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = ./libft

CC = gcc -g 

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(LIBFT)/libft.a $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L$(LIBFT) -lft

clean: 
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean bonus fclean re