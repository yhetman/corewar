/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle&parse_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 07:08:32 by user              #+#    #+#             */
/*   Updated: 2019/09/25 22:02:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static inline void	fill_types(t_carriage *carriage, char carry_codage, int id)
{
	if (carry_codage == 1)
		carriage->arg_type[id] = T_REG;
	if (carry_codage == 2)
		carriage->arg_type[id] = T_DIR;
	if (carry_codage == 3)
		carriage->arg_type[id] = T_IND;
}

void				parse_types(t_cw *cw, t_carriage *carriage, t_op *op)
{
	char			codage;
	char			carry_codage;

	if (op->codage)
	{
		codage = cw->map[(carriage->pc + 1) % MEM_SIZE];
		if (op->num_args >= 1)
		{
			carry_codage = ((codage & 192) >> 6);
			fill_types(carriage, carry_codage, 0);
		}
		if (op->num_args >= 2)
		{
			carry_codage = ((codage & 48) >> 4);
			fill_types(carriage, carry_codage, 1);
		}
		if (op->num_args >= 3)
		{
			carry_codage = ((codage & 12) >> 2);
			fill_types(carriage, carry_codage, 2);
		}
	}
	else
		carriage->arg_type[0] = op->arg_type[0];
}


static inline void	respawn_live_nums(t_cw *cw)
{
	int				i;

	i = -1;
	while (++i < cw->num_players)
	{
		cw->player[i].prev_lives = cw->player[i].crnt_lives;
		cw->player[i].crnt_lives = 0;
	}
	cw->num_lives = 0;
}

static inline void	clear_dead_carriages(t_cw *cw)
{
	t_carriage *prev;
	t_carriage	*crnt;
	t_carriage	*del;

	prev = NULL;
	crnt = cw->carriage;
	while (crnt)
	{
		del = crnt;
		if ((cw->cycles_to_die <= 0 || ((cw->cycles - del->last_cycle_check) \
		>= cw->cycles_to_die)) && cw->num_carriages--)
		{
			crnt = crnt->next;
			if (cw->carriage == del)
				cw->carriage = crnt;
			if (prev)
				prev->next = crnt;
			ft_memdel((void **)&del);
		}
		else
		{
			prev = crnt;
			crnt = crnt->next;
		}
	}
}

void				check_cycles_to_die(t_cw *cw)
{
	cw->num_checks++;
	clear_dead_carriages(cw);
	if (cw->num_checks == MAX_CHECKS || cw->num_lives >= NBR_LIVE)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->num_checks = 0;
	}
	respawn_live_nums(cw);
	cw->cycles_after_check = 0;
}