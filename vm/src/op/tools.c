/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:41:17 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carriage	*clone_carriage(t_carriage *crnt_carriage, int carry)
{
	int		i;
	t_carriage	*new_carriage;

	i = 0;
	carry = calc_pos(crnt_carriage->pc + carry);
	new_carriage = initialize_carriage(crnt_carriage->player, carry);
	while (++i < REG_NUMBER)
		new_carriage->reg[i] = crnt_carriage->reg[i];
	new_carriage->carrys = crnt_carriage->carrys;
	new_carriage->last_cycle_check = crnt_carriage->last_cycle_check;
	return (new_carriage);
}

int		bytecode_to_int(const unsigned char *map, int size, int position)
{
	int		i;
	int		res;
	bool	minus;

	i = 0;
	res = 0;
	minus = (bool)(map[(position) % MEM_SIZE] & 128);
	while (size)
	{
		if (minus)
			res += ((map[(position + size - 1) % MEM_SIZE] ^ 255) << (i * 8));
		else
			res += map[(position + size - 1) % MEM_SIZE] << (i * 8);
		i++;
		size--;
	}
	if (minus)
		res = ~res;
	return (res);
}

void	int_to_bytecode(unsigned char *map, int position, int value, int size)
{
	int		i;

	i = 0;
	while (size)
	{
		map[calc_pos(position + size - 1)] =
		(unsigned char)((value >> i) & 255);
		i += 8;
		size--;
	}
}

int		parse_args(t_cw *cw, t_carriage *carriage, int arg_num, t_op *op)
{
	int		id;
	int		res;
	int		position;

	res = 0;
	position = 0;
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	if (carriage->arg_type[ID(arg_num)] == T_REG)
		res = carriage->reg[id];
	else if (carriage->arg_type[ID(arg_num)] == T_DIR)
		res = bytecode_to_int(cw->map, op->label_size,
		calc_pos(carriage->pc + carriage->carry));
	else if (carriage->arg_type[ID(arg_num)] == T_IND)
	{
		position = bytecode_to_int(cw->map, IND_SIZE,
		calc_pos(carriage->pc + carriage->carry));
		if (carriage->op_id != 1 && carriage->op_id != 13)
			position = position % IDX_MOD;
		res = bytecode_to_int(cw->map, DIR_SIZE, carriage->pc + position);
	}
	carriage->carry += carry_size(carriage->arg_type[ID(arg_num)], op);
	return (res);
}
