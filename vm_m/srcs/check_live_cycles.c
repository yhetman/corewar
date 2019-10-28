/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_cycles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:25:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 17:47:53 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_live_cycles(t_vm *vm)
{
	long	i;

	i = -1;
	vm->checks++;
	delete_corpse(vm);
	if (vm->checks == MAX_CHECKS || vm->lives >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks = 0;
	}
	while (++i < vm->amount_of_champs)
	{
		vm->champ[i]->prev_live = vm->champ[i]->curr_live;
		vm->champ[i]->curr_live = 0;
	}
	vm->lives = 0;
}
