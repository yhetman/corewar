/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:40:46 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/29 16:54:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		op_aff(t_vm *vm, t_carriage *car)
{
	long	reg;
	long	val;

	car->step += 2;
	reg = vm->arena[next_op(car->next_op + car->step)];
	val = car->registers[reg - 1];
	car->step++;
}
