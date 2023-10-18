NAME = libftprintf.a
SOURCES = \

OBJECTS = $(SOURCES:..c=.o)

cc = gcc
CFLAGS = -Wall -Wextra - Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:
	clean all

PHONY: all clean fclean re

