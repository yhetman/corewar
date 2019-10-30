/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_placement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:00:03 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 20:28:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_carriage	*add_champ_info(t_carriage *carr, t_champion *champ)
{
	static unsigned long	index;

	carr->champ = ++index;
	carr->registers[0] = -(champ->id);
	carr->champion = champ;
	return (carr);
}

static void			carriage_cycle_list(t_carriage **all, t_carriage *last)
{
	if (last)
		last->next = *all;
	*all = last;
}

static void			readiness_message(t_vm *vm)
{
	long			index;

	index = 0;
	ft_printf("\t\t\t|===TOURNAMENT===STANDINGS===|\n");
	while (++index <= vm->amount_of_champs)
	{
		ft_printf("\t\t\t|--CHAMPION-NUMBER--|%d| WHOSE NAME IS \"%s\" ",
				index, vm->champs[index - 1]->head->prog_name);
		ft_printf("ALWAYS FOLLOW HIS MOTTO \"%s\" SO NOW HE'S READY TO WIN!\n",
				vm->champs[index - 1]->head->comment);
	}
}

int					carriages_placement(t_vm *vm)
{
	long			players;
	unsigned long	next_op;
	t_carriage		*new_carr;

	players = 0;
	next_op = 0;
	while (++players < vm->amount_of_champs)
	{
		if (!(new_carr = (t_carriage*)malloc(sizeof(t_carriage))))
			return (0);
		ft_bzero(new_carr, sizeof(t_carriage));
		add_champ_info(new_carr, vm->champs[players]);
		new_carr->next_op = next_op;
		carriage_cycle_list(&(vm->carriages), new_carr);
		vm->amount_of_carr++;
		next_op += MEM_SIZE / vm->amount_of_champs;
	}
	readiness_message(vm);
	return (1);
}
