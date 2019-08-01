NAME = checker

SRCS = 	main.c\
		parser.c\
		worker.c\
		freebufs.c\
		supfun1.c\
		supfun2.c\
		supfun3.c\
		ft_pa_supfun4.c\
		ft_pb_supfun5.c

OBJ = 	main.o\
		parser.o\
		worker.o\
		freebufs.o\
		supfun1.o\
		supfun2.o\
		supfun3.o\
		ft_pa_supfun4.o\
		ft_pb_supfun5.o

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
