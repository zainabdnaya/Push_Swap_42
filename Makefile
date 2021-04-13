# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 08:58:20 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/04/13 10:55:09 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= checker
NAME2= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
LIB_PATH= libft

SRC_NAME1= 	checker.c\
			errors.c\
			to_use.c\
			simple_free.c\
			list.c\
			moves.c\
			orderby.c\
			gen_sort.c\
			ok_ko.c\
			print.c\
			list_op.c\
			checker_rd.c\
			initial.c\
			get_next_line.c\
			get_next_line_utils.c\

SRC_NAME2=  swap.c\
			moves.c\
			list.c\
			to_use.c\
			simple_free.c\
			print.c\
			gen_sort.c\
			algo.c\
			algo_use.c\
			ok_ko.c\
			list_op.c\
			algo_500.c\
			algo_min.c\
			errors.c\
			swap_case.c\
			initial.c\

HDR_NAME= push_swap.h

OBJ_NAME1= $(SRC_NAME1:.c=.o)
OBJ1= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME1))
SRC1= $(addprefix $(SRC_PATH)/,$(SRC_NAME1))

OBJ_NAME2= $(SRC_NAME2:.c=.o)
OBJ2= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME2))
SRC2= $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME1) $(NAME2)

$(NAME1) : $(LIB_PATH)/$(LIB) $(OBJ1)
	@rm -rf $(NAME1)
	@$(COMP) $(H_FLAG) $(LLIB_FLAG) $(OBJ1) -o $@
	@echo "	Compilation of $(NAME1):  \033[1;32mOK\033[m"

$(NAME2) : $(LIB_PATH)/$(LIB) $(OBJ2)
	@rm -rf $(NAME2)
	@$(COMP) $(H_FLAG) $(LLIB_FLAG) $(OBJ2) -o $@
	@echo "	Compilation of $(NAME2):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<
lib:
	@make -sC $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME1)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME1)all obbjects are deleted.\033[0m" 
	@rm -rf $(NAME2)
	@echo "\033[0;31m>> $(NAME2) all obbjects are deleted.\033[0m" 

re : fclean all