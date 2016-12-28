# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 16:34:31 by cgodonoa          #+#    #+#              #
#    Updated: 2016/12/27 01:34:43 by cgodonoa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = includes/libft/libft.a
GCCW = gcc -Wall -Wextra -Werror
SRC = src/addition.c src/main.c src/solve.c

all: $(NAME)

$(NAME): $(LIB) 
	$(GCCW) -I./includes -c $(SRC)
	$(GCCW) addition.o solve.o main.o $(LIB) -o $(NAME)  
$(LIB):
	cd ./includes/libft && make

clean:
	cd ./includes/libft && make clean
	/bin/rm -rf addition.o solve.o main.o

fclean: clean
	cd ./includes/libft && make fclean
	/bin/rm -rf $(NAME)

re: fclean all
