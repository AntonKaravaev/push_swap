NAME = push_swap

SRCS = 	main.c\
		parser.c\
		worker.c\
		worker_sup1.c\
		worker_sup2.c\
		worker_sup3.c\
		freebufs.c\
		supfun1.c\
		supfun2.c\
		supfun3.c\
		ft_pa_supfun3.c\
		ft_pb_supfun4.c

OBJ = 	main.o\
		parser.o\
		worker.o\
		worker_sup1.o\
		worker_sup2.o\
		worker_sup3.o\
		freebufs.o\
		supfun1.o\
		supfun2.o\
		supfun3.o\
		ft_pa_supfun3.o\
		ft_pb_supfun4.o

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
