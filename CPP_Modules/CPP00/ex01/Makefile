# Name
NAME = My_Awesome_Phonebook

# Sources and objects.
SRCS = phonebook.cpp contact.cpp main.cpp add.cpp search.cpp
OBJS = $(SRCS:.cpp=.o)

# Define all the compiling flags.
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Compile and create everything.
all: $(NAME)

# Compile the program with the objects.
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

# Won't run if the source files don't exist or are not modified.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed."

re:     fclean all

.PHONY: all clean fclean format re