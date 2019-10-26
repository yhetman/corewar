/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:39:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:47:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_sti(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;
	int32_t	addr_1;
	int32_t	addr_2;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	value = cursor->registers[INDEX(r_id)];
	cursor->step += REG_LEN;
	addr_1 = get_op_arg(vm, cursor, 2, true);
	addr_2 = get_op_arg(vm, cursor, 3, true);
	int32_to_bytecode(vm->arena,
			(cursor->next_op + ((addr_1 + addr_2) % IDX_MOD)), value, DIR_SIZE);
	if (vm->vs)
		update_map(vm, cursor, cursor->next_op + ((addr_1 + addr_2) % IDX_MOD), DIR_SIZE);
}
