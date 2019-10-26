/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:43:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:47:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t	addr_1;
	int32_t	addr_2;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, 1, true);
	addr_2 = get_op_arg(vm, cursor, 2, true);
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->registers[INDEX(r_id)] = bytecode_to_int32(vm->arena,
			cursor->next_op + (addr_1 + addr_2), DIR_SIZE);
	cursor->step += REG_LEN;
}
