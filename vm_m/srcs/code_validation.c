/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:23:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 19:22:14 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	validate_params(t_carriage *carr, t_op *option)
{
	char	args_type;
	int		args;

	args = 0;
	args_type = read_one_byte(vm, carr->next_op, args);
	if (option->args_type)
	{
		while (++args <= 3)
			if (option->count_args >= args)
				memorize_arguments(((char)(args_type & (0x300 / (4 * args))) >> 6 / args), args, carr);
	}
}

void	code_calidation(t_vm *vm, t_carriage *carr, t_op *option)
{
	if (validate_params(carr, option))
		*f[option->id]();
	else
		carr->step += count_steps(carr, option);
}
