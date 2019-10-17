/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:39:43 by user              #+#    #+#             */
/*   Updated: 2019/10/17 11:14:34 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lfork(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int		carry;
	t_carriage	*new_carriage;

	carriage->carry++;
	carry = parse_args(cw, carriage, 1, op);
	new_carriage = clone_carriage(carriage, carry);
	add_carriage(&(cw->carriage), new_carriage);
	cw->num_carriages++;
}
