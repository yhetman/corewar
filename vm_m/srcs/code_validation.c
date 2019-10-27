/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:23:09 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/27 18:25:03 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	code_calidation(t_vm *vm, t_carriage *carr, t_op *option)
{
	if (validate_params(carr, option))
		*f[option->id]();
	else
		carr->step += count_steps(carr, option);
}
