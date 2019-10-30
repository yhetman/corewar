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
	 get_champions.c tools.c clear.c print.c code_validation.c op_tools.c\
	 check_live_cycles.c op_live.c op_ld.c op_st.c op_add.c op_sub.c op_and.c\
	 op_or.c op_xor.c op_zjmp.c op_ldi.c op_sti.c op_fork.c op_lld.c op_lldi.c \
	 op_lfork.c op_aff.c check_option_params.c

OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))

OBJDIR=./objs/

SRCDIR=srcs/

vpath %.c srcs/ srcs/op_functions/

NAME=corewar

FLAGS=-Wall -Wextra -Werror

DEBUG=-g3 -fsanitize=address

INCLUDE=-I./includes/

LIBNAME=libft.a

LIBPATH=./libft/

ASMPATH=./srcs/assembler

all: $(NAME) make_asm

make_asm:
	make -C $(ASMPATH)
	@mv $(ASMPATH)/asm .

$(NAME): $(OBJDIR) $(LIBPATH)$(LIBNAME) $(OBJ)
	gcc $(FLAGS) $(LIBPATH)$(LIBNAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
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
	make clean -C $(ASMPATH)
	make clean -C $(LIBPATH)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	make fclean -C $(ASMPATH)
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
