/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:24:39 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 20:31:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_ldi(t_vm *vm, t_carriage *car)
{
	long	reg;
	long	ptr_1;
	long	ptr_2;


	car->step += 2;
	ptr_1 = check_option_params(vm, car, true, 1);
	ptr_2 = check_option_params(vm, car, true, 2);
	reg = vm->arena[next_op(car->next_op + car->step)];
	cursor->registers[reg] = bytes_into_long(vm->arena,
				(car->next_op + ((ptr_1 + ptr_2) % IDX_MOD)), DIR_SIZE);
	cursor->step++;
}
