# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 14:44:07 by yhetman           #+#    #+#              #
#*   Updated: 2019/10/24 08:43:25 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS= main.c					\
	  go_to_assembler.c			\
	  great_initialization.c 	\
	  great_freeing.c			\
	  store_all_token_details.c	\
	  file_checker.c			\
	  get_command_info.c		\
	  get_command_arguments.c	\
	  rewrite_file.c			\
	  catch_tokens.c			\
	  debug.c					\
	  init.c					\
	  clear.c					\
	  writing_process.c 

OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))
OBJDIR=./obj/
SRCDIR=sources/
NAME=assembler
FLAGS=#-Wall -Wextra -Werror
DEBUG=-g3 -fsanitize=address
INCLUDE=-I./includes/ -I./asmlib/includes
ASMLIB=asmlib.a
ASMLIB_PATH=./asmlib/

all:$(NAME)

EOC = \033[0m
COLOR1= \033[38;5;44m
COLOR2= \033[38;5;45m
COLOR3 = \33[38;5;51m
COLOR4 = \033[38;5;87m
COLOR5 = \033[38;5;52m
COLOR6 = \033[38;5;81m

$(NAME): $(OBJDIR) $(ASMLIB_PATH)$(ASMLIB) $(OBJ)
	@printf "$(COLOR2) >>$(EOC) $(COLOR1)$(NAME) is ready.$(EOC)\n"
	@gcc $(FLAGS) $(INCLUDE) $(ASMLIB_PATH)$(ASMLIB) -o $(NAME)

$(OBJDIR):
	@printf "$(COLOR4)\t\t|\t\tCONSTRUCTING ASSEMBLER\t\t|$(EOC)\n"
	@mkdir $(OBJDIR)

debug: debugflags debuglib all

debugflags:
	$(eval FLAGS=$(FLAGS) $(DEBUG))

debuglib:
	make debug -C ./asmlib

$(OBJDIR)%.o:$(SRCDIR)%.c
	@printf "$(COLOR3)||||$(EOC)"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@
	@ar -r $(ASMLIB_PATH)$(ASMLIB) $@
	@ranlib $(ASMLIB_PATH)$(ASMLIB)

$(ASMLIB_PATH)$(ASMLIB):
	@printf "$(COLOR6)|\tConstructing asmlib:  $(EOC)"
	@make -C $(ASMLIB_PATH)

lib:
	@printf "$(COLOR6)|\tRecompiling asmlib:  $(EOC)"
	@make -C $(ASMLIB_PATH)

clean:
	@printf "$(COLOR5)\t\t|\tObject files are deleted!\t\t|\n$(EOC)"
	@make clean -C $(ASMLIB_PATH)
	@rm -rf obj/

fclean: clean
	@printf "$(COLOR5)\t\t|\tAssembler executable file deleted!\t|\n$(EOC)"
	@make fclean -C $(ASMLIB_PATH)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
