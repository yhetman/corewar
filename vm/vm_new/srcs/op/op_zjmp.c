/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:34:28 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:37:07 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	if (cursor->carry)
	{
		if (vm->vs)
			clear_cursor(vm, cursor);
		cursor->next_op = calc_addr(cursor->next_op + (addr % IDX_MOD));
		if (vm->vs)
			draw_cursor(vm, cursor);
		cursor->step = 0;
	}
}
