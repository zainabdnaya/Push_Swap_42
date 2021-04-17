# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 08:58:20 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/04/17 02:02:51 by zainabdnaya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= checker
NAME2= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
# LIB_PATH= libft

SRC_NAME1= errors.c\
			use_libft1.c\
			use_libft.c\
			simple_free.c\
			to_use.c\
			ok_ko.c\
	checker.c\
# 			list.c\
# 			moves.c\
# 			orderby.c\
# 			gen_sort.c\
# 			print.c\
# 			list_op.c\
# 			checker_rd.c\
# 			initial.c\

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
			use_libft1.c\
			use_libft.c\
			swap_op.c\
			# algo_min_c.c\
			# algo_c.c\
			# algo_500_c.c\
			# algo_disp.c\
			# algo_min_d.c\
			# algo_d.c\

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

COMP= gcc

all: $(NAME1) $(NAME2)

$(NAME1) :  $(OBJ1)
	@rm -rf $(NAME1)
	@$(COMP) $(H_FLAG) $(OBJ1) -o $@
	@echo "	Compilation of  $(NAME1):  \033[1;32mOK\033[m"

$(NAME2) : $(OBJ2)
	@rm -rf $(NAME2)
	@$(COMP) $(H_FLAG) $(OBJ2) -o $@
	@echo "	Compilation of $(NAME2):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME1)
	@echo "\033[0;31m>> $(NAME1)all obbjects are deleted.\033[0m" 
	@rm -rf $(NAME2)
	@echo "\033[0;31m>> $(NAME2) all obbjects are deleted.\033[0m" 

re : fclean all