/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:38:50 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int	id;

	(void)op;
	carriage->carry += 2;
	id = cw->map[calc_pos(carriage->pc + carriage->carry)];
	carriage->carry++;
	if (cw->print_aff)
		ft_printf("Aff: %c\n", (char)carriage->reg[id]);
}
