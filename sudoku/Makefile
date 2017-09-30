NAME = sudoku
CC = gcc
FLAGS = -Werror -Wall -Wextra

SRCS = main.c srcs/ft.c srcs/sudoku.c
OBJ = main.o ft.o sudoku.o

IDIR = ./includes

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRCS) -I $(IDIR)
	$(CC) -o $(NAME) $(OBJ)
	
clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all