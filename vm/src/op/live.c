/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:39:53 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/corewar.h"

void			live(t_cw *cw, t_carriage *carriage, t_op *op)
{
	int			id;
	t_player	*player;

	carriage->carry++;
	player = NULL;
	id = parse_args(cw, carriage, 1, op);
	cw->num_lives++;
	carriage->last_cycle_check = cw->cycles;
	if (id <= -1 && id >= -((int)cw->num_players))
	{
		player = &cw->player[ID(ABS(id))];
		player->last_cycle_check = cw->cycles;
		player->crnt_lives++;
		cw->last_player = player;
	}
}
