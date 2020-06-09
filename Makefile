# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 16:20:24 by orantane          #+#    #+#              #
#    Updated: 2020/01/22 12:57:18 by orantane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/*.c

OBJ = *.o

HEADER = srcs/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

.PHONY = all re clean fclean
