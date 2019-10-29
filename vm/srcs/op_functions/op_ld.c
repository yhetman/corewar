/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:31:02 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 16:54:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_ld(t_vm *vm, t_carriage *car)
{
	long	val;
	long	reg;

	car->step += (1 + 1);
	val = check_option_params(vm, car, true, 1);
	car->carry = (bool)(!val);
	reg = vm->arena[next_op(car->next_op + car->step)];
	car->registers[reg - 1] = val;
	car->step += 1;
}
