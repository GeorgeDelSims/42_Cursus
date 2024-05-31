#!/bin/bash

# Prompt for the project name
echo "Enter the project name:"
read PROJECT_NAME

# Prompt for the source files
echo "Enter the source files (space-separated):"
read SOURCE_FILES

# Generate the object files list
OBJECT_FILES=$(echo $SOURCE_FILES | sed 's/\.cpp/\.o/g')

# Create the Makefile
cat <<EOL > Makefile
# Name
NAME = $PROJECT_NAME

# Sources and objects.
SRCS = $SOURCE_FILES
OBJS = \$(SRCS:.cpp=.o)

# Define all the compiling flags.
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Compile and create everything.
all: \$(NAME)

# Compile the program with the objects.
\$(NAME): \$(OBJS)
	@\$(CXX) \$(OBJS) -o \$@

# Won't run if the source files don't exist or are not modified.
%.o: %.cpp
	\$(CXX) \$(CXXFLAGS) -o \$@ -c \$<

clean:
	@rm -f \$(OBJS)
	@echo "[INFO] Objects removed."

fclean: clean
	@rm -f \$(NAME)
	@echo "[INFO] \$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
EOL

echo "Makefile created successfully."
