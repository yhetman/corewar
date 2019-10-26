/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:18:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/26 14:25:42 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void				op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t		player_id;
	t_player	*champ;

	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, false);
	vm->lives++;
	cursor->cycle_live = vm->cycles;
	champ = NULL;
	if (player_id <= -1 && player_id >= -((int32_t)vm->amount_of_champs))
	{
		champ = vm->champs[INDEX(FT_ABS(player_id))];
		champ->cycle_live = vm->cycles;
		champ->current_lives_num++;
		vm->alive = champ;
	}
}
