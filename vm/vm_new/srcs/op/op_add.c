/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:09:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:26:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_add(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->registers[INDEX(r1_id)] + cursor->registers[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->registers[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
}
