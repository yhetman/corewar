/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:13:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:19:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	value = cursor->registers[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (vm->display_aff)
		ft_printf("Aff: %c\n", (char)value);
	if (vm->vs)
	{
		vm->vs->aff_symbol = (char)value;
		vm->vs->aff_player = cursor->champ;
	}
}
