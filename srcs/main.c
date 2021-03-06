/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:37:30 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/31 00:16:52 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_champion	*check_champions_list(t_champion *all, long id)
{
	t_champion		*champ;

	champ = all;
	if (id < 0 || id > MAX_PLAYERS)
		return (NULL);
	while (champ)
	{
		if (champ->id == id)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}

static t_vm			*malloc_vm(t_vm *vm)
{
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		vm_exit("| HUI TEBE A NE PAMYAT |\n", NULL);
	ft_bzero(vm, sizeof(t_vm));
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->dump_cycle = -1;
	return (vm);
}

static void			check_dump(int *ac, char ***av, t_vm *vm)
{
	if (!vm->dump_print_mode && *ac >= 2 && IS_INT(*(*av + 1)))
	{
		if ((vm->dump_cycle = ft_atoi(*(*av + 1))) < 0)
			vm->dump_cycle = -1;
		vm->dump_print_mode = 64;
		(*ac) -= 2;
		(*av) += 2;
	}
	else
		usage();
}

static int			start_virtual_machine(t_vm *vm, t_champion *champs)
{
	long			id;
	unsigned long	next_op;

	id = 0;
	next_op = 0;
	if (vm->amount_of_champs < 1 || vm->amount_of_champs > MAX_PLAYERS)
		return (0);
	while (id < vm->amount_of_champs)
	{
		if (!(vm->champs[id] = check_champions_list(champs, id)))
			usage();
		ft_memcpy(&(vm->arena[next_op]), vm->champs[id]->code,
				(size_t)(vm->champs[id]->head->prog_size));
		next_op += MEM_SIZE / vm->amount_of_champs;
		++id;
	}
	vm->alive = vm->champs[vm->amount_of_champs - 1];
	if (!carriages_placement(vm))
		return (0);
	return (1);
}

int					main(int ac, char **av)
{
	t_vm		*vm;
	t_champion	*champs;

	av++;
	if (!(--ac))
		usage();
	champs = NULL;
	vm = NULL;
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
		vm_exit("ERROR! Invalid amount of champions!", vm);
	execute_champs_code(vm);
	print_result(vm);
	return (0);
}
