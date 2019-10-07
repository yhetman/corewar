# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 14:44:07 by yhetman           #+#    #+#              #
#*   Updated: 2019/10/07 03:00:11 by yhetman          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS= main.c				\
	  go_to_assembler.c		\
	  great_initialization.c \
	  great_freeing.c
OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))
OBJDIR=./obj/
SRCDIR=sources/
NAME=asm
FLAGS=-Wall -Wextra -Werror
DEBUG=-g3 -fsanitize=address
INCLUDE=-I./includes/
LIBNAME=libft.a
ASMLIB=asmlib.a
ASMLIB_PATH=./asmlib/
LIBPATH=./libft/

all:$(NAME)

$(NAME): $(OBJDIR) $(LIBPATH)$(LIBNAME) $(ASMLIB_PATH)$(ASMLIB) $(OBJ)
	gcc $(FLAGS) $(INCLUDE) $(LIBPATH)$(LIBNAME) $(ASMLIB_PATH)$(ASMLIB) -o $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@
	ar -rv $(LIBPATH)$(LIBNAME) $@
	ranlib $(LIBPATH)$(LIBNAME)

$(LIBPATH)$(LIBNAME):
	make -C $(LIBPATH)

$(ASMLIB_PATH)$(ASMLIB):
	make -C $(ASMLIB_PATH)

makelibft:
	make -C $(LIBPATH)

makeasmlib:
	make -C $(ASMLIB)

makelib: makelibft makeasmlib

clean:
	make clean -C $(LIBPATH)
	make clean -C $(ASMLIB_PATH)
	rm -rf obj/

fclean: clean
	make fclean -C $(LIBPATH)
	make fclean -C $(ASMLIB_PATH)
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
