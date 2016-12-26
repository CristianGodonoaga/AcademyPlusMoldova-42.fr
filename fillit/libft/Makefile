# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgodonoa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 16:34:31 by cgodonoa          #+#    #+#              #
#    Updated: 2016/12/25 21:30:16 by cgodonoa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCCW = gcc -Wall -Wextra -Werror
SRC =	*.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(GCCW) -I./includes -c $(SRC)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJECT)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
