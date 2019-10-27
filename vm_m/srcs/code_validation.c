/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:23:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 00:28:34 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static long	count_operation(long next_op_code)
{
	next_op_code %= MEM_SIZE;
	if (next_op_code < 0)
		next_op_code += MEM_SIZE;
	return (next_op_code);
}

static int	check_register(t_vm *vm, long next_op, unsigned long step)
{
	char	reg;

	reg = (vm->arena[count_operation(carr->next_op + step)];
	return ((reg >= 1 && reg <= REG_NUMBER) ? 0 : 1);
}

static int	validate_arguments(t_vm *vm, t_carriage *carr, t_op *option)
{
	long			count;
	unsigned long	step;

	count = -1;
	step = (1 + (option->args_bc ? 1 : 0));
	while (++count < option->count_args)
	{
		if (!(carr->args_type[count] & option->args_type[count]))
			return (1);
		if ((carr->args_type[count] == T_REG)
				&& check_register(vm, carr->next_op, step))
			return (1);
		step += size_of_step(carr->args_types[count], option);
	}
	return (0);
}

static int	get_command_arguments(t_vm *vm, t_carriage *carr, t_op *option)
{
	char	args_type;
	int		args;

	args = 0;
	if (option->args_type)
	{
		args_type = (vm->arena[count_operation(carr->next_op + 1)];
		while (++args <= 3)
			if (option->count_args >= args)
				carr->args_types[args - 1] =
					T_REG << (char)(args_type & 0x300 / (4 * args) >> 6 / args) - 1;
	}
	else
		carr->args_type[0] = op->args_types[0];
	return (0);
}

void	code_validation(t_vm *vm, t_carriage *carr, t_op *option)
{
	get_command_arguments(vm, carr, option);
	if (!validate_arguments(vm, carr, option))
		*f[option->id]();
	else
		carr->step += count_steps(carr, option);
}
