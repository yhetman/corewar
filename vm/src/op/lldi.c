/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:13 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void	lldi(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	res_1;
	int	res_2;
	int	id;

	carriage->carry += 2;
	res_1 = parse_args(cw, carriage, 1, op);
	res_2 = parse_args(cw, carriage, 2, op);
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->reg[id] = bytecode_to_int(cw->map,
									carriage->pc + (res_1 + res_2),
									DIR_SIZE);
	carriage->carry++;
}
