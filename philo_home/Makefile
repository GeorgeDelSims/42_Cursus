# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsims <gsims@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:37:13 by gsims             #+#    #+#              #
#    Updated: 2024/02/20 17:24:44 by gsims            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES = ./srcs/main.c ./srcs/init.c ./srcs/input.c ./srcs/utils.c \
	./srcs/routine.c ./srcs/philos.c ./srcs/time.c ./srcs/monitor.c\
	./srcs/free.c\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

clean: 
	-rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 