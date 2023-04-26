# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpassar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 18:54:57 by adpassar          #+#    #+#              #
#    Updated: 2023/04/17 18:49:49 by adpassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.adpassar

SRC = src/push_swap.c

OBJ = $(SRC:.c=,o)

all: $(NAME)

$(NAME): $(OBJ)
		# @echo "⌛ compiling...⌛"
        $(MAKE) -s -C libft/
        $(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBFT) -o $(NAME)
        # @echo "🎉 push_swap compiled! 🎉"

clean:  
        @echo "🧽 cleaning... 🧽"
        @rm -f $(OBJ)
        @make clean -s -C libft/

fclean: clean
        @echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮" 
        rm -rf $(NAME)

re: fclean all

.SILENT:
