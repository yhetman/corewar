/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:57:44 by yhetman           #+#    #+#             */
/*   Updated: 2019/10/30 16:51:16 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

long	next_op(long next_op_code)
{
	next_op_code %= MEM_SIZE;
	if (next_op_code < 0)
		next_op_code += MEM_SIZE;
	return (next_op_code);
}

void	long_into_bytes(unsigned char *arena, long bytes, long value,
		long size)
{
	short	b;

	b = 0;
	while (size)
	{
		arena[next_op(bytes + size - 1)] = (unsigned char)((value >> b) & 0xFF);
		b += 8;
		size--;
	}
}

long	bytes_into_long(const unsigned char *arena, long bytes, long size)
{
	long	result;
	int		i;
	bool	sign;

	result = 0;
	i = 0;
	sign = (bool)(arena[next_op(bytes)] & 0x80);
	while (size)
	{
		if (sign)
			result += ((arena[next_op(bytes + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[next_op(bytes + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

long	check_option_params(t_vm *vm, t_carriage *car, bool turn,
		unsigned short i)
{
	t_op	*option;
	long	val;
	long	bytes;

	val = 0;
	option = &g_option[car->code - 1];
	if (car->args[i - 1] & T_REG)
		val = car->registers[vm->arena[next_op(car->next_op + car->step)] - 1];
	else if (car->args[i - 1] & T_DIR)
		val = bytes_into_long(vm->arena, car->next_op + car->step,
								option->command_size);
	else if (car->args[i - 1] & T_IND)
	{
		bytes = bytes_into_long(vm->arena, car->next_op + car->step, IND_SIZE);
		val = bytes_into_long(vm->arena,
							car->next_op + (turn ? (bytes % IDX_MOD) : bytes),
							DIR_SIZE);
	}
	car->step += arg_length(car->args[i - 1], option);
	return (val);
}
