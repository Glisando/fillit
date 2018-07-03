# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 17:07:17 by hdanylev          #+#    #+#              #
#    Updated: 2018/07/03 15:52:11 by hdanylev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =	main.c \
		ft_valid.c \
		ft_read_file.c \
		ft_figures.c \
		ft_map.c \
		ft_backtrack.c \
		ft_sqrt.c \
		ft_strlen.c \
		ft_strdel.c \
		ft_putstr.c

OBJ = $(SRC:.c=.o)
HDR = fillit.h
GCC = gcc
GCC_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(GCC) $(GCC_FLAGS) -c $(SRC)
	@$(GCC) $(GCC_FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[31mfillit \033[35mcompiled\033[0m"

clean:
	rm -f $(OBJ)
	@echo "\033[35mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[35mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re
