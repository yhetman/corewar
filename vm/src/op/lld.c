/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:06 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void	lld(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	id;
	int res;

	carriage->carry += 2;
	res = parse_args(cw, carriage, 1, op);
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->reg[id] = res;
	carriage->carrys = carriage->reg[id] ? false : true;
	carriage->carry++;
}