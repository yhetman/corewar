/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:38:33 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	id_1;
	int	id_2;
	int	id_3;

	(void)op;
	carriage->carry += 2;
	id_1 = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->carry++;
	id_2 = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->carry++;
	id_3 = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->reg[id_3] = carriage->reg[id_1] + carriage->reg[id_2];
	carriage->carrys = carriage->reg[id_3] ? false : true;
	carriage->carry++;
}
