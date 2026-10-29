SRC = $(shell find src/ -name "*.c")
OBJ = $(SRC:.c=.o)
NAME = my_bsq
COMPILER = gcc
INCLUDE = -I ./include/
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

all : $(OBJ)
	$(COMPILER) $(OBJ) -o $(NAME) $(FLAGS)

re : fclean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

.c.o:
	$(COMPILER) $(FLAGS) -c $< -o $@ $(INCLUDE)