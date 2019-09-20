# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 19:03:20 by yhetman           #+#    #+#              #
#    Updated: 2019/09/20 19:06:39 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -f
CFLAGS	:=	-Wall -Wextra -Werror
LIBDIR	:=	./libft
LIBFT	:=	$(LIBDIR)/libft.a
BFLAGS	:=	-I$(LIBDIR)/ -Iinclude
DEBUG	:=	-g3 -fsanitize=address -fsanitize=undefined
INCLUDE	:=	-lft -L$(LIBDIR)/
NAME	:=	asm

SRC_PATH		= 	./sources/
SRC_NAME :=		op.c main.c

SRC					=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_PATH			:= 	./obj/
OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME			=	$(SRC_NAME:.c=.o)
MAIN		=	main.c
MAINO		=	$(OBJ_PATH)main.o
H_FILES		:=	includes/op.h
DEPS		=	$(H_FILES) Makefile
TOOLDIR		:=	./tools

all: $(NAME)

$(LIBFT): force
	@$(MAKE) -C $(LIBDIR) 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEPS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(BFLAGS) $< -c -o $@ 

$(NAME): $(DEPS) $(LIBFT) $(OBJ) $(MAINO)
	$(CC) $(CFLAGS) $(BFLAGS) $(INCLUDE) $(OBJ) $(MAINO) -o $@

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)
	$(RM) tags

re: fclean all
 
force:
	@true
.PHONY: all, re, clean, fclean
