/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:06:50 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 20:15:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_xor(t_vm *vm, t_carriage *car)
{
	long	value_1;
	long	value_2;
	long	value_3;
	long	reg;

	car->step += 2;
	value_1 = check_option_params(vm, car, true, 1);
	value_2 = check_option_params(vm, car, true, 2);
	value_3 = value_1 ^ value_2;
	car->carry = (bool)(!value);
	reg = [vm->arena[next_op(car->next_op + car->step)]];
	car->registers[reg - 1] = value_3;
	car->step++;
}
