# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpassar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 18:54:57 by adpassar          #+#    #+#              #
#    Updated: 2023/04/27 19:40:18 by adpassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c checks.c src/sorting/execute_sorting_three.c  \
      src/moves/push.c src/moves/rotate.c src/moves/swap.c

OBJ = $(SRC:.c=,o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fPIE -g

LIBFT = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
        @echo "⌛ compiling...⌛"
        $(MAKE) -s -C libft/
        $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
        @echo "🎉 push_swap compiled! 🎉"

clean:  
        @echo "🧽 cleaning... 🧽"
        @rm -f $(OBJ)
        @make clean -s -C libftprintf/

fclean: clean
        @echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮" 
        @rm -rf $(NAME)
        @make fclean -s -C libftprintf/

re: fclean all

.SILENT: $(OBJ)
