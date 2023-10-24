NAME = libftprintf.a
SOURCES = \
		  utils.c	ft_printf.c	utils2.c	utils3.c	test.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = libft

c = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJECTS)
			make -C $(LIBFT_DIR)
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJECTS)

.PHONY: libft
libft:
	$(MAKE) - C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

