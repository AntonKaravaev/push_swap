NAME = push_swap

SRCS = 	main.c\
		parser.c\
		worker.c\
		worker_sup1.c\
		prewhirling.c\
		prewhirling_sup1.c\
		whirling.c\
		whirling_sup1.c\
		find_best_order.c\
		freebufs.c\
		supfun1.c\
		supfun2.c\
		supfun3.c\
		supfun4.c\
		ft_pa_supfun3.c\
		ft_pb_supfun4.c\

OBJ = 	main.o\
		parser.o\
		worker.o\
		worker_sup1.o\
		prewhirling.o\
		prewhirling_sup1.o\
		whirling.o\
		whirling_sup1.o\
		find_best_order.o\
		freebufs.o\
		supfun1.o\
		supfun2.o\
		supfun3.o\
		supfun4.o\
		ft_pa_supfun3.o\
		ft_pb_supfun4.o\

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -g -c $(SRCS) -I ./libft
	@gcc $(OBJ) -L libft/ -lft -o $(NAME) -g

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
