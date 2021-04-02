# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 08:58:20 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/04/02 08:58:46 by zainabdnaya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

LIB = ./libft/libft.a

LIB_PATH = ./libft

INCLUDES = -I libft/includes -I ./includes

CH_PATH = ./srcs/checker

PS_PATH = ./srcs/push_swap

OBJ_PATH = ./objs_ch

OBJ_PATH2 = ./objs_ps

CH_NAME =  	main.c\
			checker.c\

PS_NAME = swap.c\

CH_OBJ = $(CH_NAME:.c=.o)

PS_OBJ = $(PS_NAME:.c=.o)

CH_SRC = $(addprefix $(CH_PATH)/, $(CH_NAME))

PS_SRC = $(addprefix $(PS_PATH)/, $(PS_NAME))

OBJ1 = $(addprefix $(OBJ_PATH)/, $(CH_OBJ))

OBJ2 = $(addprefix $(OBJ_PATH2)/, $(PS_OBJ))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ1)
	@make -C $(LIB_PATH)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(OBJ1) $(INCLUDES) $(LIB) -o $(NAME)
	@echo "\x1b[36m[CHECKER COMPILED]\x1b[0m"

$(NAME2): $(OBJ2)
	@make -C $(LIB_PATH)
	@mkdir -p $(OBJ_PATH2)
	@$(CC) $(CFLAGS) $(OBJ2) $(INCLUDES) $(LIB) -o $(NAME2)
	@echo "\x1b[36m[PUSH_SWAP COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(CH_PATH) /%.c 
	@make -C $(LIB_PATH)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(OBJ_PATH2)/%.o : $(PS_PATH)/%.c  
	@mkdir -p $(OBJ_PATH2)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ1)
	@rm -rf $(OBJ2)
	@echo "\033[33mall $(NAME) and $(NAME2) .o files are removed\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) $(NAME2)
	@echo "\033[31m$(NAME) and $(NAME2) is deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re