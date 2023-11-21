NAME = libftprintf.a
SOURCES = \
	utils.c ft_printf.c utils2.c utils3.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT	= libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(MAKE)	-C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
