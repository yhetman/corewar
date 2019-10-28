/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_champs_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <yhetman@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:17:25 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 19:18:59 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	output_dump_memory(t_vm *vm)
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
	return (0);
}

static void	check_numb_of_cycles(t_vm *vm, t_carriage *carr)
{
	if (carr->cycles == 0)
	{
		carr->code = vm->arena[carr->next_op];
		if (vm->arena[carr->next_op] >= 0x01 && vm->arena[carr->next->op] <= 0x10)
			carr->cycles = g_option[carr->code - 1].cycles;
	if (carr->cycles > 0)
		carr->cycles--;

}

static long	calculate_next_op(long	next_op_code)
{
	next_op_code %= MEM_SIZE;
	if (next_op_code < 0)
		next_op_code += MEM_SIZE;
	return (next_op_code);
}

static int	op_apply(t_vm *vm, t_carriage *carr)
{
	t_op	*option;

	check_numb_of_cycles(vm, carr);
	if (carr->cycles == 0)
	{
		option = NULL;
		if (carr->code >= 0x01 && carr->code <= 0x10)
			option = &g_option[carr->code - 1];
		if (option)
			code_validation(vm, carr, option);
		else
			carr->step = 1;
		carr->next_op += cursor->step;
		carr->next_op = calculate_next_op(cursor->next_op);
		carr->step = 0;
		ft_bzero(carr->args, 3);
	}
	return (0);
}

int			execute_champs_code(t_vm *vm)
{
	t_carriage	*ex_carr;

	while (vm->amount_of_carr)
	{
		if (vm->dump_cycle == vm->cycles && !output_dump_memory(vm))
			exit(0);
		vm->cycles++;
		vm->cycles_after_check++;
		ex_carr = vm->carriages;
		while (ex_carr && !op_apply(vm, ex_carr, ex_carr->cycles))
			ex_carr = ex_carr->next;
		if (vm->cycles_to_die = vm->cycles_after_check
				|| vm->cycles_to_die <= 0)
			check_live_cycles(vm);
	}
}
