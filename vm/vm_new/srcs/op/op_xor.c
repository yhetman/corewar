/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:33:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:34:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_xor(t_vm *vm, t_cursor *cursor)
{
	int32_t	value_1;
	int32_t	value_2;
	int32_t	value;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	value_1 = get_op_arg(vm, cursor, 1, true);
	value_2 = get_op_arg(vm, cursor, 2, true);
	value = value_1 ^ value_2;
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->registers[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
}
