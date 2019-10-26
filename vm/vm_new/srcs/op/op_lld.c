/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:42:01 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:47:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_lld(t_vm *vm, t_cursor *cursor)
{
	int32_t	value;
	int32_t	r_id;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, false);
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->next_op, cursor->step);
	cursor->registers[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
}
