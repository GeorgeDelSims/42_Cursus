NAME = so_long

SOURCES = main.c keypress_utils.c keypress_utils2.c map_utils.c map_utils2.c map_utils3.c map_utils4.c small_utils.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT  = ./libft

MLX = ./mlx

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -I$(MLX)

MAKE = make

%.o: %.c
	$(CC) -Wall -Wextra -I$(MLX) -I$(LIBFT) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(MLX)/libmlx.a $(OBJECTS)
	$(CC) $(OBJECTS) -L$(MLX) -lmlx -L$(LIBFT) -lft -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(MLX)/libmlx.a:
	$(MAKE) -C $(MLX)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re