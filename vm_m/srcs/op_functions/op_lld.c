/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:24:17 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 21:28:56 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void				op_lld(t_vm *vm, t_carriage *car)
{
	long	val;
	long	reg;

	car->step += 2;
	val = check_option_params(vm, car, false, 1);
	car->carry = (bool)(!val);
	reg = vm->arena[next_op(car->next_op + car->step)];
	car->registers[reg - 1] = val;
	car->step++;
	i
