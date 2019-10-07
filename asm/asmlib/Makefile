# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 18:43:09 by yhetman           #+#    #+#              #
#*   Updated: 2019/10/07 05:20:14 by yhetman          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = asmlib.a

FLAGS =#  -Wno-missing-braces -g0 #-Wall -Wextra -Werror

FUNCTIONS = count_lines_and_signs ft_strdel ft_strdup	\
			op ft_bzero ft_putchar_fd ft_putstr_fd		\
			ft_strnew ft_strlen find_words ft_strsub

OBJ  = $(addprefix obj/, $(addsuffix .o, $(FUNCTIONS)))
SRC = $(addprefix src/, $(addsuffix .c, $(FUNCTIONS)))

HEADERS = -I./includes/*
HEADER_ASMLIB= ./includes/asmlib.h

EOC = \033[0m
GREEN = \033[38;5;31m
RED = \033[38;5;32m
PURPLE = \33[38;5;80m
CYAN = \033[38;5;81m

OBJ_PATH = obj

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(HEADER_ASMLIB)
	@printf " $(RED)>>$(EOC) $(GREEN)$(NAME) is ready.$(EOC)\n"
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ): obj/%.o: src/%.c $(HEADER_ASMLIB)
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $<
	@printf "$(CYAN)||||$(EOC)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re
