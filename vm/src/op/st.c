/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:45 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void	st(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	id;
	int	res;
	int	position;

	(void)op;
	carriage->carry += 2;
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	res = carriage->reg[id];
	carriage->carry++;
	if (carriage->arg_type[1] == T_IND)
	{
		position = bytecode_to_int(cw->map, IND_SIZE,
			carriage->pc + carriage->carry);
		int_to_bytecode(cw->map,
			carriage->pc + (position % IDX_MOD), res, DIR_SIZE);
		carriage->carry += 2;
	}
	else
	{
		position = cw->map[calc_pos(carriage->pc + carriage->carry)];
		carriage->reg[position] = res;
		carriage->carry++;
	}
}
