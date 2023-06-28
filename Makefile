# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpassar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 18:54:57 by adpassar          #+#    #+#              #
#    Updated: 2023/06/19 17:35:30 by adpassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap
# CHECK = checker

# SRCS =  $(wildcard src/*.c utils/*.c)
# CHECK_SRCS = $(wildcard utils/*.c) src/instructions.c checker.c

# OBJS = ${SRCS:.c=.o}
# CHECK_OBJS = ${CHECK_SRCS:.c=.o}

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# RM = rm -rf

# all: ${NAME} ${CHECK}
# ${NAME}: ${OBJS}
# 	@${MAKE} -C ./libft
# 	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

# ${CHECK}: ${CHECK_OBJS} 
# 	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

# clean: 
# 	@${MAKE} -C ./libft fclean
# 	@${RM} ${OBJS}
# 	@${RM} ${CHECK_OBJS}

# fclean: clean
# 	@${RM} ${NAME}
# 	@${RM} ${CHECK}

# re: fclean all

# .PHONY: all clean fclean re

############################################################################################

# NAME = push_swap

# SRC = src/main.c src/checks.c src/sorting/execute_sorting.c src/sorting/simple_sort.c \
#       src/moves/push.c src/moves/rotate.c src/moves/swap.c

# OBJ = $(SRC:.c=.o)

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -fPIE -g

# LIBFT = libftprintf/libft.a

# all: $(NAME)

# $(NAME): $(OBJ)
# 	@echo "⌛ compiling...⌛"
# 	@cd libftprintf && $(MAKE)
# #	$(MAKE) -s -C libftprintf/
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
# 	@echo "🎉 push_swap compiled! 🎉"

# clean:
# 	@echo "🧽 cleaning... 🧽"
# 	@rm -f $(OBJ)
# 	@cd libftprintf/src && rm -f $(OBJ)
# #	@cd libftprintf && rm -f $(OBJ)
# #	@cd libftprintf/ && cd src && rm -f $(OBJ)
# 	@make clean -s -C libftprintf/

# fclean: clean
# 	@echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮"
# 	@rm -rf $(NAME)
# 	@make fclean -s -C libftprintf/

# re: fclean all

# $(OBJ): %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY: all clean fclean re

############################################################################################

# # Config ---------------------------------------------------------------------->

# NAME        := push_swap
# LIB        	:= ft 
# LIB_TARGET 	:= lib/libft/libft.a
# INCS        := \
# 	./include \
# 	lib/libft/include
# SRC_DIR     := src
# SRCS        := \
# 	push_swap.c checks.c src/sorting/execute_sorting.c src/sorting/simple_sort.c \
# #       src/moves/push.c src/moves/rotate.c src/moves/swap.c
# SRCS        := $(SRCS:%=$(SRC_DIR)/%)
# CHECKER		:= \
# 	lib/libft/src/_get_next_line/ft_get_next_line.c \
# 	src/push_swap_checker.c \
# 	src/push_swap_actions.c \
# 	src/lst/t_stack_is_sorted.c \
# 	src/lst/t_stack_add_back.c \
# 	src/lst/t_stack_set_to_head.c \
# 	src/lst/t_stack_new.c \
# 	src/lst/t_stack_check_dup.c \
# 	src/lst/t_stack_n_is_inside.c \
# 	src/lst/t_stack_free.c
	
# BUILD_DIR   := .build
# OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# DEPS        := $(OBJS:.o=.d)
# CC          := clang
# CFLAGS      := -g -Wall -Wextra -Werror
# CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
# LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
# LDLIB      	:= $(addprefix -l,$(LIB))
# RM          := rm -rf
# MAKEFLAGS   := --no-print-directory
# DIR_DUP     = mkdir -p $(@D)

# .PHONY: clean fclean re
# .SILENT:

# # Rules ----------------------------------------------------------------------->

# all: banner $(NAME) 

# $(NAME): $(OBJS) $(LIB_TARGET)
# 	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
# 	${info }
# 	${info ${BOLD}Creating  -> ${BLUE}$(NAME)${NO_COLOR}}

# $(LIB_TARGET):
# 	$(MAKE) -C $(@D)

# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(DIR_DUP)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
# 	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

# -include $(DEPS)

# clean:
# 	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
# 	$(RM) $(BUILD_DIR)
# 	$(RM) checker.d
# 	${info }
# 	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}	🧹 🧹 🧹}

# fclean: clean
# 	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
# 	$(RM) $(NAME)
# 	$(RM) checker 
	
# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# bonus: banner $(LIB_TARGET)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $(CHECKER) $(LIB_TARGET) -o checker
# 	${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}

# # Style ----------------------------------------------------------------------->

# RED 		:= ${shell tput setaf 1}
# YELLOW		:= ${shell tput setaf 3}
# BLUE		:= ${shell tput setaf 4}
# NO_COLOR	:= ${shell tput sgr0}
# BOLD		:= ${shell tput bold}

# banner:
# 	${info ${RED}}
# 	${info ________             __ _ _ _______                    }
# 	${info ___/ __ \__  _______/ /_ _ _ / ___/      ______ _____  }
# 	${info __/ /_/ / / / / ___/ __ \_ _ \__ \ | /| / / __ `/ __ \ }
# 	${info _/ ____/ /_/ (__  ) / / /_ _ _ / / |/ |/ / /_/ / /_/ / }
# 	${info /_/    \__,_/____/_/ /_/_ _/____/|__/|__/\__,_/ .___/  }
# 	${info _                                            /_/       }
# 	${info ${NO_COLOR}}

# # ------------------------------------------------------------------------------

NAME = push_swap

SRC = main.c checks.c sorting/execute_sorting.c sorting/simple_sort.c \
		moves/push.c moves/rotate.c moves/swap.c

SRC_DIR = ./src/

SRCP = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCP:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE -g

LIB = ./libftprintf/libft.a

all: lib $(NAME)

lib:
	make -s -C libftprintf

$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME) 🚀"
	@gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "Compiled ✅\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects 🧹"
	@rm -rf $(OBJ) $(OBJ_B)
	@make clean -s -C libftprintf/

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"
	@rm -rf $(NAME)
	@rm -rf checker
	@make fclean -s -C libftprintf/

re: fclean all

.SILENT: $(OBJ) lib $(OBJ_B)