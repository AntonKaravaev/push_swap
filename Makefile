NAME = push_swap

SRCS = 	push_swap.c\
		parselines.c\
		supfun1.c\
		supfun2.c\
		supfun3.c


OBJ = 	push_swap.o\
		parselines.o\
		supfun1.o\
		supfun2.o\
		supfun3.o


INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS) -I ./libft
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
