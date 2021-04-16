# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 20:40:04 by zdnaya            #+#    #+#              #
#    Updated: 2019/11/11 12:07:58 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

INC = libft.h
	
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c ft_strlcpy.c \
	  ft_strchr.c ft_strdup.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	  ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
	  ft_strtrim.c ft_substr.c ft_putchar_fd.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
		@ar rc $(NAME) $(OBJ)
	   	@ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -I $(INC) -o  $@ -c  $<

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re: fclean all
