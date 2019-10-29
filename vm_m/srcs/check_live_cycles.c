/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_cycles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:25:22 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 18:24:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	replace_carriages(t_carriage *previous, t_carriage *current)
{
	previous = current;
	current = current->next;
}

static int	count_cycles(t_vm, t_carriage *corpse, t_read deadline)
{
	if (deadlive <= 0 || vm->cycles - corpse->cycle_live >= deadline)
	{
		vm->amount_of_carr--;
		return (0);
	}
	else
		return (1);
}

static void	define_corpse(t_vm *vm)
{
	t_carriage	*corpse;
	t_carriage	*curr;
	t_carriage	*prev;

	prev = NULL;
	curr = vm->carriages;
	while (curr)
	{
		corpse = curr;
		if (!count_cycles(vm, corpse, vm->cycles_to_die))
		{
			curr = curr->next;
			if (vm->carriages == corpse)
				vm->carriages = curr;
			if (prev)
				prev->next = curr;
			ft_memdel((void **)&corpse);
		}
		else
			replace_carriages(prev, curr);
}

void	check_live_cycles(t_vm *vm)
{
	long	i;

	i = -1;
	vm->checks++;
	define_corpse(vm);
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
