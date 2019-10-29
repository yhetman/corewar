#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/08/29 10:35:46 by blukasho          #+#    #+#             *#
#*   Updated: 2019/10/27 10:14:54 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS=carriages_placement.c execute_champs_code.c main.c check_byte_code.c\
	 get_champions.c tools.c clear.c print.c code_validation.c\
	 check_live_cycles.c op_functions/op_live.c op_functions/op_ld.c \
	op_functions/op_st.c op_functions/op_add.c op_functions/op_sub.c \
	op_functions/op_and.c op_functions/op_or.c op_functions/op_xor.c \
	op_functions/op_zjmp.c op_functions/op_ldi.c op_functions/op_sti.c \
	op_functions/op_fork.c op_functions/op_lld.c op_functions/op_lldi.c \
	op_functions/op_lfork.c op_functions/op_aff.c 

OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))

OBJDIR=./objs/

SRCDIR=srcs/

NAME=corewar

FLAGS=-Wall -Wextra -Werror

DEBUG=-g3 -fsanitize=address

INCLUDE=-I./includes/

LIBNAME=libft.a

LIBPATH=./libft/

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBPATH)$(LIBNAME) $(OBJ)
	gcc $(FLAGS) $(LIBPATH)$(LIBNAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/op_functions

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@
	ar -rv $(LIBPATH)$(LIBNAME) $@
	ranlib $(LIBPATH)$(LIBNAME)

$(LIBPATH)$(LIBNAME):
	make -C $(LIBPATH)

debug: debugflags debuglib all

debugflags:
	$(eval FLAGS=$(FLAGS) $(DEBUG))

debuglib:
	make debug -C $(LIBPATH)

makelib:
	make -C $(LIBPATH)

clean:
	make clean -C $(LIBPATH)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
