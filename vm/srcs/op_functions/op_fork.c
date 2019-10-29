/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:50:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 21:13:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void			op_fork(t_vm *vm, t_carriage *car)
{
	long		ptr;
	t_carriage	*new;

	car->step++;
	ptr = check_option_params(vm, car, true, 1);
	new = copy_carriage(car, ptr % IDX_MOD);
	add_carriage(&(vm->carriages), new);
	vm->amount_of_carr++;
}
