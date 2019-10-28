/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:57:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/28 19:06:46 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

int32_t		bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

long		check_option_params(t_vm *vm, t_carriage *carriage, bool turn,  unsigned short i)
{
	t_op		*option;
	long		val;
	long		bytes;

	val = 0;
	option = &g_option[carriage->code - 1];
	if (carriage->args[ i - 1] & T_REG)
		val = carriage->registers[get_one_byte(vm, carriage->next_op, carriage->step) - 1];
	else if (carriage->args[i - 1] & T_DIR)
		val = bytes_into_long(vm->arena,
								carriage->next_op + carriage->step,
								option->size);
	else if (carriage->args[i - 1] & T_IND)
	{
		bytes = bytes_into_long(vm->arena,
								carriage->next_op + carriage->step,
								IND_SIZE);
		val = bytes_into_long(vm->arena,
							carriage->next_op + (turn ? (bytes % IDX_MOD) : bytes),
							DIR_SIZE);
	}
	carriage->step += size_of_step(carriage->arg[i - 1], option);
	return (val);
}
