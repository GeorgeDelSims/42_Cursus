NAME = push_swap

SOURCES = ./srcs/main.c ./srcs/operations.c ./srcs/utils.c ./srcs/input_parsing.c \
./srcs/utilslst.c ./srcs/utilslst2.c ./srcs/free.c ./srcs/operations2.c \
./srcs/operations3.c ./srcs/cost.c ./srcs/cost2.c \

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