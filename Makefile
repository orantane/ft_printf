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

NAME = libft//printf.a

SRC_DIR = ./srcs/

SRC_NAME = 

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ = $(SRC_NAME:%.c=%.o)

LIB = libft/libft.a

HEADER = 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(HEADER)

$(OBJ):
	gcc $(FLAGS) -c $(SRC)

re: fclean all

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

.PHONY = all re clean fclean
