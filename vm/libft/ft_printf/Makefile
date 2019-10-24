# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voksenui <voksenui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 21:30:50 by voksenui          #+#    #+#              #
#    Updated: 2019/10/24 13:29:02 by blukasho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=address

LIB			=	libft/
LIB_N		=	libft.a

SRC			=	process_diuoxp.c cast_specifics.c ft_printf.c \
			 parse.c process_c.c process_pr.c process_s.c \
			 process_f.c


OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra
C			=	gcc

all: $(NAME)

debug: debugflags all

debugflags:
	$(eval FLAGS=$(FLAGS) $(DEBUGFLAGS))

$(NAME): $(OBJ)
	make -C $(LIB)
	cp $(LIB)$(LIB_N) $(NAME)
	ar -r $(NAME) $(OBJ)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all

