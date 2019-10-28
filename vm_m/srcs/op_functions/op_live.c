/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:35:56 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 18:48:25 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_functions.h"

void	op_live(t_vm *vm, t_carriage *carriage)
{
	long		name;
	t_champion	*champ;

	champ = NULL;
	carriage->step += 1;
//	name = check_option_params(vm, carriage, 1);
	vm->lives++;
	carriage->cycle_live = vm->cycles;
	if (name <= -1 && name >= -(long)(vm->amount_of_champs))
	{
		champ = vm->champs[ABS(name) - 1];
		champ->cycle_live = vm->cycles;
		champ->curr_live++;
		vm->alive = champ;
	}
}
