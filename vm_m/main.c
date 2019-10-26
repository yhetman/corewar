/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:37:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 00:59:55 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_champion	*check_champions_list(t_champion *all, long id)
{
	t_champion		*champ;

	champ = NULL;
	if (id < 1 || id > MAX_PLAYERS)
		return (NULL);
	champ = all;
	while (champ)
	{
		if (champ->id == id)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}

static t_vm	*malloc_vm(t_vm *vm)
{
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		vm_exit("| MEMORY ALLOCAION FAILED |\n", NULL);
	ft_bzero(vm, sizeof(t_vm));
	vm->cyc_reminder = CYCLE_TO_DIE;
	vm->dump_cycle = -1;
	return (vm);
}

static void	check_dump(int *ac, char ***av, t_vm *vm)
{
	if (!vm->dump_print_mode && *ac >= 2
			&& IS_INT(*(*av + 1)))
	{
		if ((vm->dump_cycle = ft_atoi(*(*av + 1))) < 0)
			vm->dump_cycle = -1;
		vm->dump_print_mode = ((!ft_strcmp(**argv, "-d")) ? 64 : 32);
		(*ac) -= 2;
		(*av) += 2;
	}
	else
		usage();
}

static int	start_virtual_machine(t_vm *vm)
{
	long			id;
	unsigned long	next_op;

	id = 0;
	next_op = 0;
	if (vm->amount_of_champs < 1
			|| vm->amount_of_champs > MAX_PLAYERS)
		return (0);
	while (++id <= vm->amount_of_champs)
	{
		if (!(vm->champs[id - 1] = check_champions_list(champs, id)))
			usage();
		ft_memcpy(&(vm->arena[next_op]), vm->champs[id - 1]->code,
				(size_t)(vm->champs[id - 1]->code_size));
		next_op += MEM_SIZE / vm->amount_of_champs;
	}
	vm->alive = vm->champs[vm->amount_of_champs - 1];
	if (!place_carriages(vm))
		return (0);
	return (1);
//	print_intro(vm->champs, vm->amount_of_champs);
//	exec(vm);
}

int			main(int ac, char **av)
{
	t_vm		*vm;
	t_champion	*champs;

	ac--;
	av++;
	champs = NULL;
	if (!ac)
		usage();
	vm = malloc_vm(vm);
	while (ac)
	{
		if (!ft_strcmp(*av, "-dump"))
			check_dump(&ac, &av, vm);
		else if (!ft_strcmp(*av, "-n") || is_cor(*av))
			get_champions(&ac, &av, vm, &champs);
		else
			usage();
	}
	if (!(start_virtual_machine(vm, champs)))
		vm_exit("ERROR! Invalid amount of champions!", &vm);
//	print_last_alive(vm);
//	vm_exit(NULL, &vm);
	return (0);
}
						
