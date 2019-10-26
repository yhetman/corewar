/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:26:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:31:10 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

inline static void	vs_st(t_vm *vm, t_cursor *cursor, int32_t addr)
{
	if (vm->vs)
		update_map(vm, cursor, cursor->next_op + (addr % IDX_MOD), DIR_SIZE);
}

void				op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	r_value = cursor->registers[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (cursor->args[1] == T_REG)
	{
		addr = get_byte(vm, cursor->next_op, cursor->step);
		cursor->registers[INDEX(addr)] = r_value;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = bytecode_to_int32(vm->arena,
							cursor->next_op + cursor->step, IND_SIZE);
		int32_to_bytecode(vm->arena, cursor->next_op + (addr % IDX_MOD),
							r_value, DIR_SIZE);
		vs_st(vm, cursor, addr);
		cursor->step += IND_SIZE;
	}
}
