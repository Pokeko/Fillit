MKEX = gcc -Wall -Wextra -Werror -o

SRC =	sources/main.c \
		sources/ft_list.c \
		sources/ft_check.c \
		sources/ft_verif.c \
		sources/ft_free_quit.c \
		sources/ft_rd_fill.c

FLAGS = -Wall -Wextra -Werror
OBJECT = *.o
COMP = gcc -c
NAME = fillit

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(MKEX) $(NAME) $(OBJECT) -L libft/ -lft
	@mv *.o sources
	@echo "\033[32mProgram OK\033[0m"

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I libft/

clean :
	@make clean -C libft/
	@rm -f sources/*.o

fclean : clean
	@make fclean -C libft/
	@rm -f $(NAME)

re : fclean all
