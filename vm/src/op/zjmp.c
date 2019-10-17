/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:41:39 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	position;

	carriage->carry++;
	position = parse_args(cw, carriage, 1, op);
	if (carriage->carrys)
	{
		carriage->pc = calc_pos(carriage->pc + (position % IDX_MOD));
		carriage->carry = 0;
	}
}
