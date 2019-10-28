/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:07:06 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 19:38:42 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_FUNCTION_H
# define OP_FUNCTION_H

# include "corewar.h"
# include "op.h"

void					op_live(t_vm *vm, t_cursor *next_op);
void					op_ld(t_vm *vm, t_cursor *next_op);
void					op_st(t_vm *vm, t_cursor *next_op);
void					op_add(t_vm *vm, t_cursor *next_op);
void					op_sub(t_vm *vm, t_cursor *next_op);
void					op_and(t_vm *vm, t_cursor *cursor);
void					op_or(t_vm *vm, t_cursor *cursor);
void					op_xor(t_vm *vm, t_cursor *cursor);
void					op_zjmp(t_vm *vm, t_cursor *cursor);
void					op_ldi(t_vm *vm, t_cursor *cursor);
void					op_sti(t_vm *vm, t_cursor *cursor);
void					op_fork(t_vm *vm, t_cursor *cursor);
void					op_lld(t_vm *vm, t_cursor *cursor);
void					op_lldi(t_vm *vm, t_cursor *cursor);
void					op_lfork(t_vm *vm, t_cursor *cursor);
void					op_aff(t_vm *vm, t_cursor *cursor);

typedef void			(*t_op_func)(t_vm *vm, t_carriage *carr);

static t_op_func		g_op_functions[17] = {
						NULL,
						op_live,
						op_ld,
						op_st,
						op_add,
						op_sub,
						op_and,
						op_or,
						op_xor,
						op_zjmp,
						op_ldi,
						op_sti,
						op_fork,
						op_lld,
						op_lldi,
						op_lfork,
						op_aff
};


#endif
