# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/25 01:00:32 by crenly-b          #+#    #+#              #
#    Updated: 2019/08/25 14:27:41 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(NAME1) $(NAME2)

NAME1 = checker
NAME2 = push_swap

FLAGS = -Wall -Wextra -Werror -c
HEADER = -I includes -I libft/includes
LIB		= -L libft/ -lft

SRCS_PATH1 = ./checker_srcs/
SRCS_PATH2 = ./push_swap_srcs/

SRC_FILES1 = main.c\
			parser.c\
			worker.c\
			freebufs.c\
			supfun1.c\
			supfun2.c\
			ft_pa_supfun3.c\
			ft_pb_supfun4.c

SRC_FILES2 = main.c\
			parser.c\
			worker.c\
			sort_by_value.c\
			frombtoa.c\
			frombtoa_sup1.c\
			posoneelem.c\
			freebufs.c\
			supfun1.c\
			supfun2.c\
			supfun3.c\
			ft_pa_supfun3.c\
			ft_pb_supfun4.c\

SRCS1 = $(addprefix $(SRCS_PATH1)/,$(SRC_FILES1))
SRCS2 = $(addprefix $(SRCS_PATH2)/,$(SRC_FILES2))

OBJS_PATH1 = obj_checker/
OBJS_PATH2 = obj_push_swap/
OBJS_NAME1 = $(SRC_FILES1:.c=.o)
OBJS_NAME2 = $(SRC_FILES2:.c=.o)
OBJS1 = $(addprefix $(OBJS_PATH1),$(OBJS_NAME1))
OBJS2 = $(addprefix $(OBJS_PATH2),$(OBJS_NAME2))


all: $(NAME)

$(NAME1):
		@make -C libft
		@gcc $(FLAGS) $(SRCS1) $(HEADER)
		@mkdir $(OBJS_PATH1) 2> /dev/null || true
		@mv $(OBJS_NAME1) $(OBJS_PATH1)
		@gcc -o $(NAME1) $(OBJS1) $(HEADER) $(LIB)
		@echo ✅ checker compiled!

$(NAME2):
		@gcc $(FLAGS) $(SRCS2) $(HEADER)
		@mkdir $(OBJS_PATH2) 2> /dev/null || true
		@mv $(OBJS_NAME2) $(OBJS_PATH2)
		@gcc -o $(NAME2) $(OBJS2) $(HEADER) $(LIB)
		@echo ✅ push_swap compiled!

clean:
		@make -C libft/ clean
		@rm -rf $(OBJS_PATH1)
		@rm -rf $(OBJS_PATH2)

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all
