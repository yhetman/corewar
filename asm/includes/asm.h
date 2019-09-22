/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 00:21:51 by yhetman           #+#    #+#             */
/*   Updated: 2019/09/22 23:57:20 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../libft/includes/libft.h"
#include "op.h"

typedef struct			s_command
{
	char				*command;
	size_t				line;
	struct s_command	*next;
}						t_command;

typedef struct			s_reader
{
	int					line;
	int					c;
}						t_reader;

typedef struct			s_assembler
{
	car					**command;
}						t_assembler;
#endif
