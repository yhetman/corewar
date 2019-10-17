/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:40:22 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		my_fork(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int		carry;
	t_carriage	*new_carriage;

	carriage->carry++;
	carry = parse_args(cw, carriage, 1, op);
	new_carriage = clone_carriage(carriage, carry % IDX_MOD);
	add_carriage(&(cw->carriage), new_carriage);
	cw->num_carriages++;
}
