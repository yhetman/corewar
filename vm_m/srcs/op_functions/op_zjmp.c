/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:17:43 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 20:22:49 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_zjmp(t_vm *vm, t_carriage *car)
{
	long	addr;

	car->step++;
	addr = check_option_params(vm, car, true, 1);
	if (car->carry)
	{
		car->next_op = next_op(car->next_op + (addr % IDX_MOD));
		cursor->step = 0;
	}

