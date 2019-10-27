/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_champs_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:17:25 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 12:47:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	output_dump_memory(t_vm *vm)
{
	int		x;
	int		y;

	x = 0;
	while (x < MEM_SIZE)
	{
		ft_printf("%.4p : ", x);
		y = -1;
		while (++y < vm->dump_print_mode)
			ft_printf("%.2x ", vm->arena[x + y]);
		write(1, "\n", 1);
		x += vm->dump_print_mode
	}
}

static void	op_apply(t_vm	*vm, t_carriage *carr)
{
	t_op	*op;


}

int			execute_champs_code(t_vm *vm)
{
	t_carriage	*ex_carr;

	while (vm->amount_of_carr)
	{
		if (vm->dump_cycle == vm->cycles)
		{
			output_dump_memory(vm);
			exit(0);
		}
		vm->cycles++;
		vm->cycles_after_check++;
		ex_carr = vm->carriages;
		while (ex_carr)
		{
			op_apply(vm, ex_carr);
			ex_carr = ex_carr->next;
		}
		if (vm->cycles_to_die = vm->cycles->after_check
				|| vm->cycles_to_die <= 0)
			//check_cycles(vm);
	}
}
