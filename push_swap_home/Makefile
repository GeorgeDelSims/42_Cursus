# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsims <gsims@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:01:14 by gsims             #+#    #+#              #
#    Updated: 2024/02/06 17:01:15 by gsims            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = ./srcs/main.c ./srcs/operations.c ./srcs/utils.c ./srcs/input_parsing.c ./srcs/print_functions.c\
./srcs/utilslst.c ./srcs/utilslst2.c ./srcs/free.c ./srcs/operations2.c ./srcs/operations3.c ./srcs/init.c\
./srcs/operations4.c ./srcs/cost.c ./srcs/cost2.c ./srcs/sort.c ./srcs/sort2.c ./srcs/sort3.c \

OBJECTS = $(SOURCES:.c=.o)

LIBFT = ./libft

BONUS = ./bonus

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

bonus: 
	make -C $(BONUS)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean bonus fclean re