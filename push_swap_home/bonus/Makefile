NAME = ../checker_gs

SOURCES = srcs_bonus/main_bonus.c

PUSH_SWAP_SRC_DIR = ../srcs

LIBFT = ../libft

PUSH_SWAP_SOURCES = $(addprefix $(PUSH_SWAP_SRC_DIR)/,operations.c utils.c \
input_parsing.c print_functions.c utilslst.c utilslst2.c free.c operations2.c \
operations3.c operations4.c cost.c cost2.c sort.c sort2.c sort3.c init.c)

ALL_SOURCES = $(SOURCES) $(PUSH_SWAP_SOURCES)

OBJECTS = $(ALL_SOURCES:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR = ./objects_bonus

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

VPATH = srcs_bonus:$(PUSH_SWAP_SRC_DIR)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT) -lft

clean:
	rm -rf $(OBJ_DIR)	
	make -C $(LIBFT) clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean 

re: fclean all

.PHONY: all clean fclean re
