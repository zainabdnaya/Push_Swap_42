# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 08:58:20 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/04/20 15:09:09 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= checker
NAME2= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
SHARED_PATH= $(OBJ_PATH)/shared


SRC_SHARED= shared/errors.c\
			shared/simple_free.c\
			shared/use_libft1.c\
			shared/use_libft.c\
			shared/list_op.c\
			shared/to_use.c\
			shared/initial.c\
			shared/gen_sort.c\
			shared/list.c\
			shared/moves.c\
			shared/ok_ko.c\
			shared/algo_d.c\
		  	shared/algo_disp.c\
		  	shared/algo_min_d.c\
		  	shared/print.c\
		  	shared/swap_disp.c\
            shared/algo_500_c.c\
			shared/algo_min_c.c\
			shared/algo_c.c\
			shared/orderby.c\
			shared/checker_rd.c\
			shared/algo.c\
			shared/algo_use.c\
			shared/algo_500.c\
			shared/algo_min.c\
			shared/swap_case.c\
			shared/swap_op.c\
			shared/option_v.c\
			shared/algo_norm.c\
				
SRC_NAME1= checker.c  $(SRC_SHARED)
SRC_NAME2=  swap.c $(SRC_SHARED)
HDR_NAME= push_swap.h

OBJ_NAME1= $(SRC_NAME1:.c=.o)
OBJ1= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME1))
SRC1= $(addprefix $(SRC_PATH)/,$(SRC_NAME1))

OBJ_NAME2= $(SRC_NAME2:.c=.o)
OBJ2= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME2))
SRC2= $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
# FLAGS= -Wall -Wextra -Werror
H_FLAG= -I $(HDR_PATH)

COMP= gcc -g

all: $(NAME1) $(NAME2)

$(NAME1) :  $(OBJ1)
	@rm -rf $(NAME1)
	@$(COMP) $(H_FLAG) $(OBJ1) -o $@
	@echo "	Compilation of  $(NAME1):  \033[1;32mOK\033[m"

$(NAME2) : $(OBJ2)
	@rm -rf $(NAME2)
	@$(COMP)  $(H_FLAG) $(OBJ2) -o $@
	@echo "	Compilation of $(NAME2):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) $(SHARED_PATH) 
	@$(COMP)  $(FLAGS) $(H_FLAG)  -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME1)
	@echo "\033[0;31m>> $(NAME1)all obbjects are deleted.\033[0m" 
	@rm -rf $(NAME2)
	@echo "\033[0;31m>> $(NAME2) all obbjects are deleted.\033[0m" 

re : fclean all