/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:39:11 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 16:56:27 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_sti(t_vm *vm, t_carriage *car)
{
	long	reg;
	long	value;
	long	next_op_1;
	long	next_op_2;

	car->step += (1 + 1);
	reg = vm->arena[next_op(car->next_op + car->step)];
	value = car->registers[reg - 1];
	car->step++;
	next_op_1 = check_option_params(vm, car, true, 2);
	next_op_2 = check_option_params(vm, car, true, 3);
	long_into_bytes(vm->arena,
	car->next_op + ((next_op_1 + next_op_2) % IDX_MOD), value, DIR_SIZE);
}
