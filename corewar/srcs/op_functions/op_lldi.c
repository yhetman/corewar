/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:24:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 16:54:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		op_lldi(t_vm *vm, t_carriage *car)
{
	long	val_1;
	long	val_2;
	long	reg;

	car->step += 2;
	val_1 = check_option_params(vm, car, true, 1);
	val_2 = check_option_params(vm, car, true, 2);
	reg = vm->arena[next_op(car->next_op + car->step)];
	car->registers[reg - 1] = bytes_into_long(vm->arena,
			car->next_op + (val_1 + val_2), DIR_SIZE);
	car->step++;
}
