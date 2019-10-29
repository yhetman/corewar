/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:39:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 15:19:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_st(t_vm *vm, t_carriage *car)
{
	long	reg;
	long	value;
	long	op;

	car->step += (1 + 1);
	reg = vm->arena[next_op(car->next_op + car->step)];
	value = car->registers[reg - 1];
	car->step++;
	if (car->args[1] == T_REG)
	{
		op = vm->arena[next_op(car->next_op + car->step)];
		car->registers[next_op - 1] = value;
		car->step++;
	}
	else
	{
		op = bytes_into_long(vm->arena, car->next_op + car->step, IND_SIZE);
		long_into_bytes(vm->arena,
				car->next_op + (next_op % IDX_MOD), value, DIR_SIZE);
		car->step += IND_SIZE;
	}
}
