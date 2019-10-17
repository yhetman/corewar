/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:55 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	id;
	int	res;
	int	pos_1;
	int	pos_2;

	carriage->carry += 2;
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->carry++;
	res = carriage->reg[id];
	pos_1 = parse_args(cw, carriage, 2, op);
	pos_2 = parse_args(cw, carriage, 3, op);
	int_to_bytecode(cw->map, (carriage->pc + ((pos_1 + pos_2) % IDX_MOD)),
					res, DIR_SIZE);
}