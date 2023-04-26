# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpassar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 20:59:05 by adpassar          #+#    #+#              #
#    Updated: 2023/04/19 21:01:15 by adpassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc $(CFLAG) -c
CFLAG = -Wall -Werror -Wextra
RM = rm -f
LIB = ar rc $(NAME)
SRC = ft_isalpha.c\
    ft_isdigit.c\
    ft_isalnum.c\
    ft_isascii.c\
    ft_isprint.c\
    ft_strlen.c\
    ft_memset.c\
    ft_bzero.c\
    ft_memcpy.c\
    ft_memmove.c\
    ft_memccpy.c\
    ft_strlcpy.c\
    ft_strlcat.c\
    ft_toupper.c\
    ft_tolower.c\
    ft_strchr.c\
    ft_strrchr.c\
    ft_strncmp.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_strnstr.c\
    ft_atoi.c\
    ft_calloc.c\
    ft_strdup.c\
    ft_substr.c\
    ft_strjoin.c\
    ft_strtrim.c\
    ft_split.c\
    ft_itoa.c\
    ft_strmapi.c\
    ft_striteri.c\
    ft_putchar_fd.c\
    ft_putstr_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    ft_atoi_long\
    ft_putstr\
    ft_putchar\
    ft_lstnewnum
SRC_BONUS = ft_lstnew.c\
            ft_lstadd_front.c\
            ft_lstsize.c\
            ft_lstlast.c\
            ft_lstadd_back.c\
            ft_lstdelone.c\
            ft_lstclear.c\
            ft_lstiter.c\
            ft_lstmap.c\
            ft_lstadd_backnum
OBG = $(SRC:.c=.o)
OBG_BONUS = $(SRC_BONUS:.c=.o)
all: $(NAME)
$(NAME): $(OBG)
	@$(CC) $(SRC)
	@$(LIB) $(OBG) 
clean:
	@$(RM) $(OBG) $(OBG_BONUS)
fclean: clean
	@$(RM) $(NAME)
re: fclean all 
bonus: $(OBG) $(OBG_BONUS)
	@$(CC) $(SRC_BONUS)
	@$(LIB) $(NAME) $(OBG) $(OBG_BONUS)
.PHONY: all clean fclean bonus
