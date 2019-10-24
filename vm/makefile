# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:25:21 by blukasho          #+#    #+#              #
#    Updated: 2019/10/24 12:39:25 by blukasho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		corewar

DEF :=		\x1b[0m
GRN :=		\x1b[32m
YLW :=		\x1b[33m
RED :=		\x1b[31m

SRC_PATH :=	src/
OP_PATH	 := $(SRC_PATH)op/
LIB_PATH :=	libft/ft_printf/
OBJ_PATH :=	.obj/

CC		:=	clang

INC_PATH :=	includes/

CCFLAGS  := -Wall -Wextra
IFLAGS	 :=	-I $(LIB_PATH)$(INC_PATH) -I $(INC_PATH)

HFILES	 :=	corewar op corewar_error_manager
FILES	 :=	game corewar cycle_parse_types output parser support_func validator \
			
OP_FILES := add aff and ld ldi lfork live lld lldi my_fork or st sti tools \
			sub xor zjmp

LIB :=		$(LIB_PATH)libftprintf.a

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
SRCS +=		$(addprefix $(OP_PATH), $(addsuffix .c, $(OP_FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	@$(CC) $(IFLAGS) $(OBJS) $(LIB) $(CCFLAGS) -o $(NAME)
	@echo "$(GRN)Corewar is ready$(DEF)"
$(LIB): 
	@make -C $(LIB_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)$(SRC_PATH)
	@mkdir -p $(OBJ_PATH)$(OP_PATH)
	@echo "$(YLW)Directory for objects was created$(DEF)"
$(OBJ_PATH)%.o: %.c $(HDRS)
	@$(CC) $(CCFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(YLW)$(subst $(OBJ_PATH)$(SRC_PATH),,$@) was created$(DEF)"

clean: mclean
	@make clean -C $(LIB_PATH)
fclean: mfclean
	@make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	@rm -f $(OBJS) $(DEPS)
	@echo "$(RED)Objects for corewar were deleted$(DEF)"
mfclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)	
	@echo "$(RED)Directory with objects was deleted$(DEF)"
	@echo "$(RED)Corewar was deleted$(DEF)"
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
